/*
 * delays.h
 *
 * Created: 24/07/2013 14:02:48
 *  Author: Renan
 */ 

#define F_CPU 8000000

#include <util/delay.h>

void delay_1us();
void delay_10us();

void delay_1ms();
void delay_10ms();
void delay_100ms();
void delay_500ms();

void delay_ms(int delay);