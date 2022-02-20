/*
 * SD.h
 *
 * Created : 24/07/2015 14:02:48
 * Modified: 02/13/2022 12:53:01
 *  Author: Renan
 */ 

#ifndef SD_H_HEADER
#define SD_H_HEADER

#define SD_DISABLE() SETBIT(PORTB, 2);			// Desativa	SD
#define SD_ENABLE() RSTBIT(PORTB, 2);			// Ativa	SD
#define _STATUS_MMC	0x01

#include <avr/io.h>
#include "delays.h"
#include "Bits.h"

void SD_Write(uint8_t Dado);
uint8_t SD_Read();

void (* const func_write_ptr)(uint8_t);
uint8_t (* const func_read_ptr)(void);

void SD_WaitToken( );

uint8_t SD_SendCMDCRC(uint8_t CMD, uint32_t PARAM, uint8_t CRC);
uint8_t SD_SetBlockLen(uint32_t lenght);
uint8_t SD_ReadSingleBlock(uint32_t adr, int len, uint8_t *outData);

uint8_t SD_Init();

#endif /* #ifndef SD_H_HEADER */