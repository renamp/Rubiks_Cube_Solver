/*
 * UART.h
 *
 * Created: 25/07/2013 22:15:55
 *  Author: Renan
 */ 

#ifndef UART_H_
#define UART_H_

#include "avr/io.h"

void UART_init( unsigned long BAUD);

void UART_Write( unsigned char Data );

char UART_DataIsReady( );

unsigned char UART_Read( );

#endif /* UART_H_ */