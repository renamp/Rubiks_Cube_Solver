/*
 * EEPROM.h
 *
 * Created: 2/20/2022 4:15:30 PM
 *  Author: Renan
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

#include <avr/io.h>

uint8_t EEPROM_read(uint16_t Adr);
void EEPROM_write(uint16_t adr, char data);

#endif /* EEPROM_H_ */