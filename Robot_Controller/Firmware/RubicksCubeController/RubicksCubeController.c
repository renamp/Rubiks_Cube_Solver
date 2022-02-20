/*
 * TestSolucionador_atmega328p_.c
 *
 * Created: 22/02/2015 01:08:00
 *  Author: Renan
 *
 *
 */ 
 
#include "RubicksCubeController.h"

//uint8_t m[6][9];
uint8_t m[6][9] = {
	{0, 0, 5, 0, 0, 5, 4, 1, 1},
	{5, 1, 3, 5, 1, 3, 1, 1, 2},
	{3, 3, 1, 4, 2, 1, 5, 4, 4},
	{0, 5, 5, 0, 3, 3, 4, 2, 1},
	{0, 0, 3, 2, 4, 2, 0, 3, 2},
	{2, 2, 3, 5, 5, 4, 2, 4, 4}
};
	
static uint8_t orientacaoCubo;
static uint8_t centroCubo[6] = {0,1,2,3,4,5};
static uint16_t MovListIndex;
static uint8_t listBracos[12];
static uint8_t servo1[8], servo2[2], servo3[3];
static uint8_t servo1Index, servo2Index, servo3Index;
static PortPin const	servo1Pin = {&PORTC, PINC3}, 
						servo2Pin = {&PORTC, PINC4}, 
						servo3Pin = {&PORTC, PINC5};
static ServoPWM servo1PWM, servo2PWM, servo3PWM;
uint8_t MenuState, servosState;


static void ServoLoad()
{
	for( int i=0; i<8; i++)	servo1[i] = EEPROM_read(i+16);
	for( int i=0; i<2; i++)	servo2[i] = EEPROM_read(i+24);
	for( int i=0; i<3; i++)	servo3[i] = EEPROM_read(i+26);
	servo1Index = 1;
	servo2Index = 0;
	servo3Index = 0;
}

static void ServoSave()
{
	for( int i=0; i<8; i++) EEPROM_write(i+16, servo1[i]);
	for( int i=0; i<2; i++) EEPROM_write(i+24, servo2[i]);
	for( int i=0; i<3; i++) EEPROM_write(i+26, servo3[i]);
}

static void DisableInterrupt()
{
	while(servosState != 0);
	TIMSK0 = 0x00;		// Overflow Interrupt
	cli();
}

static void EnableInterrupt()
{
	servosState = 0;
	TCNT0 = 220;
	TIMSK0 = 0x01;		// Overflow Interrupt
	sei();
}

void Interpretador(uint32_t AdrMAIN, uint32_t PC, uint8_t MovList[]);

void piscaLed(int led1 , int led2){
	int maior = led1;
	if( led2 > maior ) maior = led2;
	
	for( int i=0; i<maior; i++){
		if( i<led2 ) SETBIT(PORTC, 0);
		if( i<led1 ) SETBIT(PORTC, 1);
		_delay_ms(150);
		
		RSTBIT(PORTC, 0);
		RSTBIT(PORTC, 1);
		_delay_ms(150);
	}
}

void piscaData(uint8_t data ){
	for( int j=7; j>=0; j--){
		if( GETBIT(data, j) ) piscaLed(1,0);
		else piscaLed(0,1);
	}
	_delay_ms(1000);
}




void ADDMovimento( int face, uint8_t MovList[] ){
	// se for movimento na mesma face
	if( MovListIndex>0 && (MovList[MovListIndex-1]&7) == (face&7) ) {
		// se dois movimentos
		if( GETBIT(MovList[MovListIndex-1], 4) ){
			if( GETBIT(face, 3) ) MovList[MovListIndex-1] = (face&7);
			else MovList[MovListIndex-1] = (face&7)+8;
		}
		else {
			// se dois movimentos iguais ( adiciona parametro de duas voltas)
			if( GETBIT(MovList[MovListIndex-1],3) == GETBIT(face, 3) ) MovList[MovListIndex-1] = (face&7)+16;
			// se movimentos contrarios ( remove movimento anterior)
			else MovListIndex--;
		}
	}
	else MovList[MovListIndex++] = face;
}

void Move( uint8_t face, uint8_t MovList[] ){
	uint8_t temp[3], i;
	
	ADDMovimento(face, MovList);
	
	if( face & 0x08 ) i = 3;
	else i = 1;
	face &= ~0x08;
	
	for(; i>0; i--){
		uint8_t j, op1,op2, buffer;
		uint16_t adr;
		// Rotacao da Face
		adr = (face*50);
		adr += 212;
		
		for(j=0; j<25; j++,adr++){
			buffer = EEPROM_read(adr++);
			if(GETBIT(buffer, 8)){			// se operandor temp
				op1 = (buffer & 0x0F);
				buffer = EEPROM_read(adr);
				temp[op1] = m[buffer >> 4][buffer & 0x0F];
			}
			else{							// se for m[][]
				op2 = (buffer & 0x0F);
				op1 = buffer >> 4;
				buffer = EEPROM_read(adr);
				if(GETBIT(buffer, 8))			// se operandor temp
				m[op1][op2] = temp[buffer & 0x0F];
				else
				m[op1][op2] = m[buffer >> 4][buffer & 0x0F];
			}
		}
	}
}

/////////////////////////////////////////////////
// Timer Interrupt
ISR( TIMER0_OVF_vect ){
	TCCR0B = 0x03;
	if(servosState == 0) servosState++;
	
	if(servosState == 1 
	  && ServoPWM_ISR(&servo1PWM, &servo1Pin, &TCNT0) == true)
		servosState++;
	
	if(servosState == 2 
	  && ServoPWM_ISR(&servo2PWM, &servo2Pin, &TCNT0) == true)
		servosState++;
		
	if(servosState == 3
	  && ServoPWM_ISR(&servo3PWM, &servo3Pin, &TCNT0) == true)
		servosState++;
	
	if( servosState > 3 )
	{	// set a bigger time before restart from servo 1
		TCCR0B = 0x05;
		TCNT0 = 70;
		servosState = 0;
	}
}

/**  //////////////////////////////////////////
// Rotina para Movimentacao dos Bracos
// Bit 0:1	Determina a posicao dos bracos
// Bit 2    Determina se � pra rotacionar uma Face
// Bit 3	Determina se � pra rotacionar a Base
// Bit 4	Determina se � pra Mudar de face
*/
void SetMov( uint8_t movimento ){
	uint8_t posicao = (movimento & 0x03);
	// se Rotacionar Face
	if( GETBIT(movimento, 2 ) ){
		ServoPWM_MoveWait(&servo2PWM, &servo2Pin, servo2[1], 10);	// Lower cuber lateral holder
		
		int delay = 350;
		if( posicao == 0 ){if(servo1Index==7)delay=600;servo1Index = 0;}		// rotaciona para a posicao 0
		else if( posicao == 2 ){if(servo1Index==1)delay=600;servo1Index = 6;}	// rotaciona para a posicao 2
		else if( posicao == 1 && servo1Index == 1) servo1Index = 2;				// rotaciona para o meio
		else if( posicao == 1 && servo1Index == 7) servo1Index = 4;				// rotaciona para o meio
		
		ServoPWM_MoveWait(&servo1PWM, &servo1Pin, servo1[servo1Index], 15);		// Rotate base
		servo1Index++;
		ServoPWM_MoveWait(&servo1PWM, &servo1Pin, servo1[servo1Index], 15);
		
		ServoPWM_MoveWait(&servo2PWM, &servo2Pin, servo2[0], 10);	// Rise cuber lateral holder
	}
	
	// se Rotacionar Base
	else if( GETBIT( movimento, 3 ) ){
		// Atualiza orientacao do Cubo
		uint8_t vezes=0;
		if(servo1Index==1 ) vezes = posicao;
		else if( (servo1Index==3||servo1Index==5) && posicao == 2 ) vezes = 1;
		else if( (servo1Index==3||servo1Index==5) && posicao == 0 ) vezes = 3;
		else if( servo1Index == 7 ) vezes = 2+posicao;
		for(;vezes>0; vezes-- ){
			orientacaoCubo = centroCubo[0];
			for( int i=0; i<3; i++)	centroCubo[i] = centroCubo[i+1];
			centroCubo[3] = orientacaoCubo;
		}
		
		int delay = 300;
		if( posicao == 0 ){if(servo1Index==7)delay=500; servo1Index = 1;}
		else if( posicao == 2 ){if(servo1Index==1)delay=500; servo1Index = 7;}
		else if( posicao == 1 && servo1Index == 1 ) servo1Index = 3;
		else if( posicao == 1 && servo1Index == 7 ) servo1Index = 5;
		ServoPWM_MoveWait(&servo1PWM, &servo1Pin, servo1[servo1Index], 15);		// Rotate base
		_delay_ms(300);
	}
	
	// Mudar Face
	else if( GETBIT( movimento, 4 ) ){
		for( int i=0; i<posicao; i++ ){
			// Atualiza Orientacao do Cubo
			orientacaoCubo = centroCubo[0];
			centroCubo[0] = centroCubo[5]; centroCubo[5] = centroCubo[2]; 
			centroCubo[2] = centroCubo[4]; centroCubo[4] = orientacaoCubo;
			
			ServoPWM_MoveWait(&servo3PWM, &servo3Pin, servo3[1], 50); //servo3Index = 1;
			_delay_ms(150);
			ServoPWM_MoveWait(&servo3PWM, &servo3Pin, servo3[2], 6);  //servo3Index = 2;
			ServoPWM_MoveWait(&servo3PWM, &servo3Pin, servo3[0], 20); //servo3Index = 3;
		}
	}
	
	_delay_ms(100);
}
void SetMov2( uint8_t movimento ){
	uint8_t posicao = (movimento & 0x03);
	
	// se Rotacionar Face
	if( GETBIT(movimento, 2 ) ){
		servo2Index = 1;			// abaixa apoio lateral
		//		_delay_ms(200);				// espera 100 ms
		
		if( posicao == 0 )servo1Index = 0;			// rotaciona para a posicao 0
		else if( posicao == 2 )servo1Index = 6;		// rotaciona para a posicao 2
		else if( posicao == 1 && servo1Index == 1) servo1Index = 2;		// rotaciona para o meio
		else if( posicao == 1 && servo1Index == 7) servo1Index = 4;		// rotaciona para o meio

		//		_delay_ms(600);
		servo1Index++;
		//		_delay_ms(220);
		
		servo2Index = 0;			// Levanta apoio lateral
		//		_delay_ms(200);				// espera 100 ms
	}
	
	// se Rotacionar Base
	else if( GETBIT( movimento, 3 ) ){
		// Atualiza orientacao do Cubo
		uint8_t vezes=0;
		if(servo1Index==1 ) vezes = posicao;
		else if( (servo1Index==3||servo1Index==5) && posicao == 2 ) vezes = 1;
		else if( (servo1Index==3||servo1Index==5) && posicao == 0 ) vezes = 3;
		else if( servo1Index == 7 ) vezes = 2+posicao;
		for(;vezes>0; vezes-- ){
			orientacaoCubo = centroCubo[0];
			for( int i=0; i<3; i++)	centroCubo[i] = centroCubo[i+1];
			centroCubo[3] = orientacaoCubo;
		}
		
		
		if( posicao == 0 ) servo1Index = 1;
		else if( posicao == 2 ) servo1Index = 7;
		else if( posicao == 1 && servo1Index == 1 ) servo1Index = 3;
		else if( posicao == 1 && servo1Index == 7 ) servo1Index = 5;
		//		_delay_ms(600);
	}
	
	// Mudar Face
	else if( GETBIT( movimento, 4 ) ){
		for( int i=0; i<posicao; i++ ){
			// Atualiza Orientacao do Cubo
			orientacaoCubo = centroCubo[0];
			centroCubo[0] = centroCubo[5]; centroCubo[5] = centroCubo[2];
			centroCubo[2] = centroCubo[4]; centroCubo[4] = orientacaoCubo;
			
			servo3Index = 0;
			//			_delay_ms(250);
			servo3Index = 1;
			//			_delay_ms(250);
			servo3Index = 2;
			//			_delay_ms(200);
		}
	}
	//	_delay_ms(50);
}

void printCube(uint8_t modo){

	if( modo == 2 ){
		_delay_us(15);
		for(int i=0; i<6; i++){
			for( int j=0; j<9; j++){
				UART_Write(m[i][j]);
			}
			_delay_us(30);
		}
	}
}

void Interpretador(uint32_t AdrMAIN, uint32_t PC, uint8_t MovList[]){
	uint8_t indexPC, control;
	uint32_t PCn1, PCn2, stackPC[12];
	int8_t Vars[30];
	uint32_t tempLong;
	
	//uint16_t movListIndex = 0;
	uint16_t i;
	uint8_t SDbuffer[16];
	uint8_t ServoListIndex;
	
	// Interpretador Inicio
	indexPC = 0;
	control = 0;			// Bits[ 0:Loop, 1:estado, ]
	PCn1 = 0;
	PCn2 = 0;
	ServoListIndex = 0;
	
	DisableInterrupt();
	
	// determina posicao da base do Cubo
	uint8_t baseCubo = 0;
	if( servo1Index == 3 || servo1Index == 5 ) baseCubo = 1;
	else if( servo1Index == 1) baseCubo = 0;
	else if( servo1Index == 7) baseCubo = 2;
	
	while( !GETBIT(control, 0) ){
		CarregaSetor:
		{
			//uint32_t tempLong;
			tempLong = ((PC&0x00FFFFFF)*512)+AdrMAIN + (((PC&0xFF000000)>>24) * 16);
			SD_ReadSingleBlock(tempLong, 16, SDbuffer);
		}
		
		PC += 0x01000000;
		if( (PC&0xFF000000) == 0x20000000 ){	PC++; PC &= 0x00FFFFFF; }
		
		// Operacao "if" - Inicio
		if( SDbuffer[0] == 0x21 ){
			RSTBIT(control, 1);								// Estado False
			PCn1 =  SDbuffer[1];		PCn1<<=8;
			PCn1 |= SDbuffer[2];		PCn1<<=8;
			PCn1 |= SDbuffer[3];		PCn1<<=8;
			PCn1 |= SDbuffer[4];
			
			PCn2 =  SDbuffer[5];		PCn2<<=8;
			PCn2 |= SDbuffer[6];		PCn2<<=8;
			PCn2 |= SDbuffer[7];		PCn2<<=8;
			PCn2 |= SDbuffer[8];
		}
		
		// Operacao "if" - Condicoes
		else if( SDbuffer[0] == 0x22){
			int operador1=0, operador2=0;
			
			// Carrega Operador 1
			if( SDbuffer[1] == 0x10 )									// Operador1 � uma Variavel
				operador1 = Vars[SDbuffer[2]];							
			else if( SDbuffer[1] <= 5 )									// Operador1 � a Matrix do Cubo
				operador1 = m[SDbuffer[1]][SDbuffer[2]];				
			
			// Carrega Operador 2
			if( SDbuffer[3] == 0x81 )									// Operador2 � um Numero
				operador2 = SDbuffer[4];								
			else if( SDbuffer[3] == 0x82 )								// Operador2 � a Matrix do Cubo
				operador2 = m[SDbuffer[4]][SDbuffer[5]];				
			else if( SDbuffer[3] == 0x83 )								// Operador2 � uma Variavel
				operador2 = Vars[SDbuffer[4]];							
			
			// Verifica Aritmetica
			if( SDbuffer[6] == 0x81 ){									// Aritmetica "=="
				if( operador1 == operador2 ) SETBIT(control, 1);
				else RSTBIT(control, 1);
			}
			else if( SDbuffer[6] == 0x82 ){								// Aritmetica "!="
				if( operador1 != operador2 ) SETBIT(control, 1);
				else RSTBIT(control, 1);
			}
			else if( SDbuffer[6] == 0x83 ){								// Aritmetica ">"
				if( operador1 > operador2 ) SETBIT(control, 1);
				else RSTBIT(control, 1);
			}
			else if( SDbuffer[6] == 0x84 ){								// Aritmetica "<"
				if( operador1 < operador2 ) SETBIT(control, 1);
				else RSTBIT(control, 1);
			}
			else if( SDbuffer[6] == 0x85 ){								// Aritmetica ">="
				if( operador1 >= operador2 ) SETBIT(control, 1);
				else RSTBIT(control, 1);
			}
			else if( SDbuffer[6] == 0x86 ){								// Aritmetica "<="
				if( operador1 <= operador2 ) SETBIT(control, 1);
				else RSTBIT(control, 1);
			}
			
			// Verifica Proxima Operacao ou Fim "if"
			if( SDbuffer[7] == 0x80 ){							// Fim Condicoes
				if( !GETBIT(control, 1) ){
					PC = PCn2;									// Jump Falso
					goto CarregaSetor;							// Carrega o setor
				}
			}
			else if( SDbuffer[7] == 0x81 ){						// Operador &&
				if( !GETBIT(control, 1) ){
				PC = PCn2;	goto CarregaSetor;	}				// Jump Falso
			}
			else if( SDbuffer[7] == 0x82 ){						// Operador ||
				if( GETBIT(control, 1) ){
				PC = PCn1;	goto CarregaSetor;	}				// Jump Verdadeiro
			}
		}
		
		// Instrucao de Acesso a variaveis
		else if( SDbuffer[0] == 0x26){
			int operador2=0, operador3=0;
			
			// carrega operador 2
			if( SDbuffer[2] == 0x81 )						// Operador 2 � um Numero
				operador2 = SDbuffer[3];
			else if( SDbuffer[2] == 0x82 )					// Operador 2 � uma variavel
				operador2 = Vars[SDbuffer[3]];
			
			// carrega operado 3
			if( GETBIT(SDbuffer[5], 7) )					// Operador 3 � uma Variavel
				operador3 = Vars[SDbuffer[6]];
			else											// Operado 3 � um Numero
				operador3 = SDbuffer[6];
			
			// parametros de operacao
			SDbuffer[5] = SDbuffer[5]&0x7F;
			if( SDbuffer[5] == 0 )							// Apenas Atribuicao
				Vars[SDbuffer[1]] = operador2;
			else if( SDbuffer[5] == 1 )						// Soma
				Vars[SDbuffer[1]] = operador2 + operador3;
			else if( SDbuffer[5] == 2 )						// Subtracao
				Vars[SDbuffer[1]] = operador2 - operador3;
			else if( SDbuffer[5] == 3 )						// Multiplicacao
				Vars[SDbuffer[1]] = operador2 * operador3;
			else if( SDbuffer[5] == 4 )						// Divisao
				Vars[SDbuffer[1]] = operador2 / operador3;
		}
		
		// Instrucao RETURN
		else if( SDbuffer[0] == 0x30 ){
			PC = stackPC[--indexPC];
			goto CarregaSetor;
		}
		
		// Instrucao GOTO
		else if( SDbuffer[0] == 0x31 ){
			LoadPC:
			PC = SDbuffer[1];		PC<<=8;
			PC |= SDbuffer[2];		PC<<=8;
			PC |= SDbuffer[3];		PC<<=8;
			PC |= SDbuffer[4];
			goto CarregaSetor;
		}
		
		// Instrucao CALL
		else if( SDbuffer[0] == 0x32 ){
			stackPC[indexPC++] = PC;		// armazena Adr da proxima instrucao
			goto LoadPC;					// GOTO para a Funcao
		}
		
		// Instrucao Move(face);
		else if( SDbuffer[0] == 0x33 ){
			for(i=1; i<16 && SDbuffer[i]<0xFF ; i++)
				Move(SDbuffer[i], MovList);
		}
		
		// Instrucao OV7670_Write
		else if( SDbuffer[0] == 0x34 ){
			//OV7670_Write()
		}
		
		// Instrucao orientacao do Cubo
		else if( SDbuffer[0] == 0x40 ){
//			if( SDbuffer[5] != orientacaoCubo )
//				goto LoadPC;
		}
		
		// Instrucao de comparacao para Movimento da face (Instrucao basica)
		else if( SDbuffer[0] == 0x41 ){
			uint8_t face=0;
			for( int temp=0; temp<6; temp++)
				if( centroCubo[temp] == (MovList[MovListIndex] & 0x07) ) face = (temp | (MovList[MovListIndex] & 0xF8));
			
			if( baseCubo == SDbuffer[1] && face == SDbuffer[2] ){
				for( uint8_t index=3; SDbuffer[index] != 0; index++)
					listBracos[ServoListIndex++] = SDbuffer[index];
				
				listBracos[ServoListIndex] = 0;
	//			orientacaoCubo = SDbuffer[3];	
				SETBIT(control, 0);							// Sai Loop Principal
			}
		}
		
		// Instrucao de movimento da face ( Instrucao Resumida )
		else if( SDbuffer[0] == 0x42 ){
			if( baseCubo == SDbuffer[1] ){
				for( uint8_t index=3; SDbuffer[index] != 0; index++){
					listBracos[ServoListIndex++] = SDbuffer[index];
					
					if( GETBIT( SDbuffer[index], 3) ) baseCubo = SDbuffer[index]&0x03;
				}
//				orientacaoCubo = SDbuffer[2];
				
				PC = 0x01000000;
			}
		}
		
		// Comando Fim Codigo
		else if( SDbuffer[0] == 0xF8 ){
			SETBIT(control, 0);							// Sai Loop Principal
		}
	}
	
	EnableInterrupt();
}

uint32_t findFirmware(){
	uint32_t adr=0, temp1=0,temp2=0;
	uint8_t SDbuffer[32];
	uint8_t loop=1;
	int i;

	DisableInterrupt();
	while( loop ){
		if( SD_ReadSingleBlock(adr, 32, SDbuffer) )
		{
			if( adr==0 && SDbuffer[0x00] == 0x31 && (SDbuffer[0x10]==0x31 || SDbuffer[0x10]==0xF8) ) loop = 0;
		
			// Setor da Particao de Boot
			else if( SDbuffer[0]==0xEB && SDbuffer[1]==0x3C && SDbuffer[2]==0x90 )
			{
				temp2 = SDbuffer[0xC]; temp2 <<= 8;
				temp2 |= SDbuffer[0xB];
			
				temp1 = SDbuffer[0x17]; temp1 <<= 8;
				temp1 |= SDbuffer[0x16];
				temp1 = temp1 * temp2;					// Tamanho da tabela de alocacao
			
				temp2 = SDbuffer[0x10];		
				temp1 = temp1 * temp2;
				
				adr += temp1;
				
				temp2 = SDbuffer[0xC]; temp2 <<= 8;
				temp2 |= SDbuffer[0xB];
				temp1 = SDbuffer[0xF]; temp1 <<= 8;
				temp1 |= SDbuffer[0xE];
				temp1 = temp1 * temp2;
				
				adr += temp1;							// Endereco da tabela de Diretorios
				
				temp1 = SDbuffer[0xD];					// setores por Cluster
				temp1 = temp1 * temp2;					// Bytes por Cluster
				
				// Procura pelo Firmware
				for( i=0; i<512; i++){
					temp2 = i * 32;
					SD_ReadSingleBlock(adr + temp2, 32, SDbuffer);
					
					if( (SDbuffer[0]=='F'||SDbuffer[0]=='f') && (SDbuffer[1]=='I'||SDbuffer[1]=='i') && 
					(SDbuffer[2]=='R'||SDbuffer[2]=='r') && (SDbuffer[3]=='M'||SDbuffer[3]=='m') &&
					SDbuffer[4]==' ' &&	SDbuffer[5]==' ' && SDbuffer[6]==' ' && SDbuffer[7]==' ' &&
					(SDbuffer[8]=='H'||SDbuffer[8]=='h')&&(SDbuffer[9]=='E'||SDbuffer[9]=='e')&&(SDbuffer[10]=='X'||SDbuffer[10]=='x')){
						temp2 = SDbuffer[0x1B]; temp2 <<= 8;
						temp2 |= SDbuffer[0x1A]; temp2 -= 2;
						temp1 = temp1 * temp2;			// posicao relativa do inicio do arquivo
					
						i = 512;
						adr += 0x4000 + temp1;
					}
					// se Firmware nao encontrado
					else if( i == 511 ){
						adr = 0xFFFFFFFF;
					}
				}

				loop = 0;
			}
			else 
			{
				adr += 512;
			}
		}
	}
	
	EnableInterrupt();
	return adr;
}

void setMatrix(){
	piscaLed(0,1);
	UART_Write(13);
	UART_Write('>');
	UART_Write(':');
	for(int temp,i=0; i<6; i++){
		for(int j=0; j<9; ){
			while(!UART_DataIsReady());
			temp = UART_Read();
			if( temp >= 0x30 ){ m[i][j++] = (temp-0x30);}
		}
	}
	UART_Write(13);
	UART_Write('!');
	UART_Write(13);
}

void Resolvedor(uint32_t AdrMain){
	// Executa codigo para gerar Movimentos para resolver o cubo
	piscaLed(0,1);
	
	uint8_t MovList[200];
	MovListIndex = 0;
	
	// Chama funcao para Resolver a Matriz do cubo
	Interpretador(AdrMain, 0,  MovList);
	
	UART_Write(10); UART_Write(13);
	// Envia a Lista de movimentos da Solucao via Porta Serial
	for(int i=0; i<MovListIndex; i++){
		if( GETBIT(MovList[i], 4) ) UART_Write('2');
		UART_Write('M'); UART_Write((MovList[i]&7)+0x30);
		if( GETBIT(MovList[i], 3) )UART_Write('\'');
		UART_Write(10); UART_Write(13);
	}
	UART_Write(10); UART_Write(13);
	
	piscaLed(0,1);

	// Decodifica os movimentos para os movimentos dos bracos
	uint16_t MovListLength = MovListIndex;
	int i;
	
	for( MovListIndex = 0; MovListIndex < MovListLength; MovListIndex++){		
		Interpretador(AdrMain, 0x01000000 , MovList);
		
		UART_Write(centroCubo[0]+0x30);
		UART_Write(centroCubo[4]+0x30);
		UART_Write(' ');
		
		for( i=0 ; listBracos[i] != 0 ; i++ ){
//			LeituraBotoes();
			SetMov(listBracos[i]);
			//SetMov2(listBracos[i]);
			
			if( GETBIT(listBracos[i], 2) ) UART_Write('R');
			else if( GETBIT(listBracos[i], 3) ) UART_Write('B');
			else if( GETBIT(listBracos[i], 4) ) UART_Write('C');
			UART_Write((listBracos[i]&0x3) + 0x30 );
			UART_Write(' ');
			
			_delay_ms(200);
			
			if( ((~PIND) & 0x3C) == buttonRed ){
				while(((~PIND) & 0x3C) != buttonGreen);
			}
		}
		
		UART_Write(10); UART_Write(13);
	}
	
	piscaLed(1,1);
}


void LeituraBotoes (){
	char Button = (~PIND) & 0x3C;
	
	if( Button == buttonRed || Button == buttonGreen || Button == buttonBlue || Button == buttonYellow )
	{
		_delay_ms(300);
		Button = (~PIND) & 0x3C;
		
		/////////////////////////////////////////////////////////////////
		// Menu Principal
		if( MenuState == 0 ){
			// entra no Menu
			if( Button == (buttonRed|buttonGreen|buttonBlue|buttonYellow) ){
				MenuState = 1;
				piscaLed(1,0);
			}
			
			else if( Button == buttonRed ){
				piscaLed(1,0);
				do{
					Button = (~PIND) & 0x3C;
				}while( !(Button == buttonRed) );
			}
			
			else if( Button == buttonGreen ){
				MenuState = 20;	// Menu Carrega matriz
				MovListIndex = 0;
				piscaLed(0,2);
			}
			
			else if( Button == buttonBlue ){
				uint32_t AdrMain = findFirmware();
				Resolvedor(AdrMain);
			}
			
			else if( Button == buttonYellow ){
				//TestServos();
				setMatrix();
			}
			
			else if( Button == (buttonYellow|buttonRed) ){
				
			}
			else if( Button == (buttonYellow|buttonGreen) ){
				
			}
			else if( Button == (buttonYellow|buttonBlue) ){
				
			}
		}
		
		/////////////////////////////////////////////////////////////////
		// Menu de Configuracao
		else if( MenuState > 0  && MenuState < 20 )
		{
			// Salvar e Sair
			if( Button == (buttonBlue|buttonYellow) ){
				ServoSave();
				MenuState = 0;
				servo2Index = 0;
				servo3Index = 0;
				servo1Index = 1;
			}
			// Incrementa valor da posicao
			else if( Button == buttonRed ){
				if( MenuState > 0 && MenuState < 9 ){
					servo1Index = MenuState - 1;
					servo1[servo1Index]++;
				}
				else if( MenuState == 9 || MenuState == 10 ){
					servo2Index = MenuState - 9;
					servo2[servo2Index]++;
				}
				else if( MenuState == 11 || MenuState == 12 || MenuState == 13 ){
					servo3Index = MenuState - 11;
					servo3[servo3Index]++;
				}
				
				piscaLed(0,1);
			}
			// Decrementa valor da posicao
			else if( Button == buttonGreen ){
				if( MenuState > 0 && MenuState < 9 ){
					servo1Index = MenuState - 1;
					servo1[servo1Index]--;
				}
				else if( MenuState == 9 || MenuState == 10 ){
					servo2Index = MenuState - 9;
					servo2[servo2Index]--;
				}
				else if( MenuState == 11 || MenuState == 12 || MenuState == 13 ){
					servo3Index = MenuState - 11;
					servo3[servo3Index]--;
				}
				piscaLed(0,1);
			}
			// Proxima ou Posicao Anterior do Servo
			else if( Button == buttonBlue || Button == (buttonBlue|buttonGreen) ){
				if( MenuState > 0 && MenuState < 9 ){
					if( Button == buttonBlue ) MenuState++;
					else MenuState--;
					if( MenuState == 9 ) MenuState = 1;
					else if( MenuState == 0 )MenuState = 8;
				}
				else if( MenuState == 9 || MenuState == 10 ){
					if( MenuState == 10 ) MenuState = 9;
					else MenuState = 10;
				}
				else if( MenuState == 11 || MenuState == 12 || MenuState == 13 ){
					if( MenuState == 13 ) MenuState = 11;
					else MenuState++;
				}
			}
			// Seleciona Proximo Servo para Configurar
			else if ( Button == buttonYellow ){
				if( MenuState > 0 && MenuState < 9 ){
					MenuState = 9;
				}
				else if( MenuState == 9 || MenuState == 10 ){
					MenuState = 11;
				}
				else if( MenuState == 11 || MenuState == 12 || MenuState == 13 ){
					MenuState = 1;
				}
			}
			// Atualiza posicao Do Servo
			if( Button == buttonBlue ||  Button == buttonYellow || Button==(buttonBlue|buttonGreen) ){
				if( MenuState > 0 && MenuState < 9 ){
					piscaLed(1, MenuState);
					servo1Index = MenuState - 1;
				}
				else if( MenuState == 9 || MenuState == 10 ){
					piscaLed(2, MenuState-8);
					servo2Index = MenuState - 9;
				}
				else if( MenuState == 11 || MenuState == 12 || MenuState == 13 ){
					piscaLed(3, MenuState-10);
					servo3Index = MenuState - 11;
				}
				_delay_ms(200);
			}
			servo1PWM.targetPos = servo1[servo1Index];
			servo1PWM.speed = 20;
			servo2PWM.targetPos = servo2[servo2Index];
			servo2PWM.speed = 20;
			servo3PWM.targetPos = servo3[servo3Index];
			servo3PWM.speed = 20;
		}
		
		/////////////////////////////////////////////////////////////////
		// Menu Carrega Matriz
		else if( MenuState >= 20 && MenuState < 30 ){
			if( MenuState < 26 ){
				if( Button == buttonRed ){ m[MenuState-20][MovListIndex++] = 3; piscaLed(0,1);}
				else if( Button == buttonGreen ){ m[MenuState-20][MovListIndex++] = 2; piscaLed(0,1);}
				else if( Button == buttonBlue ){ m[MenuState-20][MovListIndex++] = 0; piscaLed(0,1);}
				else if( Button == buttonYellow ){ m[MenuState-20][MovListIndex++] = 4; piscaLed(0,1);}
				else if( Button == (buttonRed|buttonGreen) ){ m[MenuState-20][MovListIndex++] = 1; piscaLed(0,1);}
				else if( Button == (buttonRed|buttonBlue) ){ m[MenuState-20][MovListIndex++] = 5; piscaLed(0,1);}
				
				if( MovListIndex == 9 ){
					if( MenuState == 20 ) SetMov(8+1);
					else if( MenuState == 21 ) SetMov(8+2);
					else if( MenuState == 22 ){ SetMov(8+1); SetMov(16+2); SetMov(8+2); SetMov(16+2); SetMov(8+1); }
					else if( MenuState == 23 ){ SetMov(8+0); SetMov(16+3); SetMov(8+1); SetMov(16+1); SetMov(8+0);}
					else if( MenuState == 24 ) SetMov(16+2);
					else if( MenuState == 25 ){ SetMov(8+1); SetMov(16+1); SetMov(8+2); SetMov(16+1);}
					MenuState++;
					MovListIndex = 0;
					
					if( MenuState == 26 ){ 
						piscaLed(2,0);
						for(int i=0; i<6; i++ ){
							for(int j=0; j<9; j++){ UART_Write(m[i][j]+0x30); UART_Write(' ');}
							UART_Write(10);UART_Write(13);
						}
					}
				}
			}
			// se matrix Completa
			else if( MenuState == 26 ){
				if( Button == buttonGreen ){
					piscaLed(0,3);
					MenuState = 0;
					uint32_t AdrMain = findFirmware();
					Resolvedor(AdrMain);
					SetMov(8+0);
				}
			}
		}
	}
}


void Init(){
	RSTBIT(MCUCR, PUD);		// habilita pull-up
	
	// Servos
	ServoLoad();
	ServoPWM_Init(&servo1PWM, &servo1Pin, servo1[servo1Index]);
	ServoPWM_Init(&servo2PWM, &servo2Pin, servo2[servo2Index]);
	ServoPWM_Init(&servo3PWM, &servo3Pin, servo3[servo3Index]);
	
	// Config Timer Interrupt
	TCCR0A	 = 0x00;
	TCCR0B   = 0x05;	// pres:1024
	TCNT0 = ServoDelay;	// 16,6ms
	TIMSK0 = 0x01;		// Overflow Interrupt
	
	// Enable Botoes
	PORTC = 0x00;
	DDRC = 0xFF;
	
	SETBIT(PORTD, 2);
	RSTBIT(DDRD, 2);	// In
	SETBIT(PORTD, 3);
	RSTBIT(DDRD, 3);	// In
	SETBIT(PORTD, 4);
	RSTBIT(DDRD, 4);	// In
	SETBIT(PORTD, 5);
	RSTBIT(DDRD, 5);	// In
	
	UART_init(250000);
	//UART_init(57600);
	
	MenuState = 0;
	sei();				// Enable all Interrupts
}

int main(void)
{
	Init();
	_delay_ms(1000);
	
Inicio:	
	
	if( SD_Init() ){
		piscaLed(1,1);
		UART_Write('!');
	}
	else {
		piscaLed(1,0);
		UART_Write('.');
		UART_Write('?');
		goto Inicio;
	}
	
	// Loop Principal
    while(1)
    {
		LeituraBotoes();
		
		if( UART_DataIsReady() ){
			int inBuffer = UART_Read();
			uint32_t AdrMain = 0;
			
			switch( inBuffer )
			{
				case 'i':
					setMatrix();
					break;
				
				case 'r':
					UART_Write('r');
					AdrMain = findFirmware();
				
				case 't':
					UART_Write(13);
					UART_Write('.');
					UART_Write('.');
					Resolvedor(AdrMain);
					break;
			}
		}
    }
			
}