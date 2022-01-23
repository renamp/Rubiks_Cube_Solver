
#include "SD.h"

void SD_Write(uint8_t Dado){
	SPDR = Dado;
	while(!(SPSR & (1<<SPIF)));
}

uint8_t SD_Read(){
	SPDR = 0xFF;
	while(!(SPSR & (1<<SPIF)));
	return SPDR;
}

uint8_t SD_SendCMDCRC(uint8_t CMD, uint32_t PARAM, uint8_t CRC){
	SD_Write( CMD | 0x40 );
	SD_Write( PARAM>>24 );
	SD_Write( PARAM>>16 );
	SD_Write( PARAM>>8 );
	SD_Write( PARAM );
	SD_Write( CRC );
	
	SD_Read();					// dummy
	return SD_Read();			// response
}

uint8_t SD_Init(){
	int i;
	
	// Inicializacao COMUNICACAO
	DDRB |= (1<<PINB5)|(1<<PINB3)|(1<<PINB2);
	clearbit(DDRB, 4);
	
	// Enable 2x SPI Speed 
	SPSR = (1<<SPI2X);
	// Enable SPI, Master, High idle, sample rising, prescaller 4
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<CPOL)|(1<<CPHA);
	
	SD_Desable();				// Desativa SD
	for(i=0; i<30; i++)
		SD_Read();				// Sincroniza
	SD_Enable();				// Ativa SD
	delay_1ms();
	
	if( SD_SendCMDCRC( 0, 0, 0x95 ) == 1 ){
		delay_100ms();
		SD_SendCMDCRC( 8, 0x1AA, 0x87 );
		delay_100ms(); delay_100ms();
		
		do{
			if(i>200) {	if( SD_SendCMDCRC( 1, 0, 0 ) == 0 ) return 1;	}
			else{
				SD_SendCMDCRC( 55, 0, 0xFF );
				if( SD_SendCMDCRC( 41, 0, 0 ) == 0 ) return 1;
			}
			
			i++;
		}while ( i < 210 );
	}
	return 0;
}

void SD_EsperaToken( ){
	while( SD_Read() != 0xFE );
}
