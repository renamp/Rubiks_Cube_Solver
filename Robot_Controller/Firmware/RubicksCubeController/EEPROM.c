/*
 * EEPROM.c
 *
 * Created: 2/20/2022 4:15:43 PM
 *  Author: Renan
 */ 

#include "EEPROM.h"

uint8_t EEPROM_read(uint16_t Adr)
{
	while(EECR & (1<<EEPE));
	EEAR = Adr;
	EECR |= (1<<EERE);
	return EEDR;
}
void EEPROM_write(uint16_t adr, char data)
{
	while(EECR & (1<<EEPE));
	EEAR = adr;
	EEDR = data;
	EECR |= (1<<EEMPE);
	EECR |= (1<<EEPE);
}