
#include "SD.h"


void SD_Write(uint8_t Dado)
{
	SPDR = Dado;
	while(!(SPSR & (1<<SPIF)));
}

uint8_t SD_Read()
{
	SPDR = 0xFF;
	while(!(SPSR & (1<<SPIF)));
	return SPDR;
}

//-------------------------------------------------------
//
//    Private Members
//
//-------------------------------------------------------

static int _blockLength = 512;							// default blockLength
static uint8_t _status;

static uint8_t SD_CheckResponseR1(uint8_t resp)
{
	if( resp == 0 )
	{
		if( _status & _STATUS_MMC )
		return 1;
		
		uint8_t i = 30;									// repeat times
		for(resp=0xFF; i && (resp&0x80); i--)
		resp = func_read_ptr();
		
		if( i ) return 1;
	}
	return 0;
}

static uint8_t SD_InitSequence()
{
	uint8_t result, i;
	
	SD_DISABLE();
	i = 30;												// repeat times
	for(; i > 0 ; i--)									// for SD Syncronization
		func_read_ptr();								// dummy 
	SD_ENABLE();
	
	i = 30;												// attempy times
	result = SD_SendCMDCRC( 0, 0, 0x95 );				// Reset card Command
	for(; (i > 0) && (result != 1); i--)
		result = func_read_ptr();
	
	if( result != 1)									// Card not initialized
		return 0;
	
	delay_100ms();
	result = SD_SendCMDCRC( 8, 0x1AA, 0x87 );

	delay_100ms(); delay_100ms();
	int retry = 120;
	do
	{
		if( retry > 60)
		{												// Init SDHC card
			_status &= (~_STATUS_MMC);					// its SD
			result = SD_SendCMDCRC( 55, 0, 0 );
			if( result == 1 )
				result = SD_SendCMDCRC( 41, 0, 0 );
			else if( result & 0x04 )
				_status |= (_STATUS_MMC);				// its MMC
		}
			
		if( (retry <= 60) || (result&0x04) )
			result = SD_SendCMDCRC( 1, 0, 0 );			// Init MMC card
			
		if( SD_CheckResponseR1(result) )
			return 1;									// Card Initilized
			
		i = 40;											// give some clocks before try again
		for(; (i > 0) && (result != 0); i-- )
			result = func_read_ptr();
			
	}while ( retry-- );
	
	return 0;
}

//-------------------------------------------------------
//
//    Public Members
//
//-------------------------------------------------------

void (* const func_write_ptr)(uint8_t) = SD_Write;
uint8_t (* const func_read_ptr)(void) = SD_Read;

void SD_WaitToken( )
{
	while( func_read_ptr() != 0xFE );
}

uint8_t SD_SendCMDCRC(uint8_t CMD, uint32_t PARAM, uint8_t CRC)
{
	func_write_ptr( CMD | 0x40 );
	func_write_ptr( PARAM>>24 );
	func_write_ptr( PARAM>>16 );
	func_write_ptr( PARAM>>8 );
	func_write_ptr( PARAM );
	func_write_ptr( CRC );
	
	func_write_ptr(0xFF);											// dummy
	return func_read_ptr();											// response
}

uint8_t SD_SetBlockLen(uint32_t lenght)
{
	uint8_t resp = SD_SendCMDCRC(16, lenght, 0);					// Set Block Lenght: CMD16
	if( SD_CheckResponseR1( resp ) )		
	{
		_blockLength = (int)lenght;
		return 1;
	}
	
	return 0;
}

uint8_t SD_ReadSingleBlock(uint32_t adr, int len, uint8_t *outData)
{
	if( len != _blockLength)
		SD_SetBlockLen(len);
	
	uint8_t resp = SD_SendCMDCRC(17, adr , 0);						// SD Read Single Block: CMD17
	if( SD_CheckResponseR1( resp ) )			
	{
		SD_WaitToken();
		for( int i=0; i<len; i++)
			outData[i] = func_read_ptr();
		func_read_ptr(); func_read_ptr(); func_read_ptr();			//  crc
		return 1;
	}
	
	return 0;
}

uint8_t SD_Init()
{
	// Init SPI ports
	DDRB |= (1<<PINB5)|(1<<PINB3)|(1<<PINB2);
	RSTBIT(DDRB, 4);
	
	//SPSR &= ~(1<<SPI2X);			// Disable 2x SPI Speed 
	SPSR |=  (1<<SPI2X);			// Enable 2x SPI Speed 
	
	// Enable SPI, Master, High idle, sample rising, prescaller 4
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<CPOL)|(1<<CPHA);
	
	uint8_t i = 2;													// try Initialization few times
	for( ; i > 0 ; i--)								
		if( SD_InitSequence() == 1 )
			return 1;
		
	return 0;
}


