
#define F_CPU 8000000

#include <avr/io.h>
#include "delays.h"
#include "Bits.h"

#define SD_Desable() setbit(PORTB, 2);			// Desativa	SD
#define SD_Enable() clearbit(PORTB, 2);			// Ativa	SD

void SD_Write(uint8_t Dado);

uint8_t SD_Read();

uint8_t SD_SendCMDCRC(uint8_t CMD, uint32_t PARAM, uint8_t CRC);

void SD_EsperaToken( );

uint8_t SD_Init();