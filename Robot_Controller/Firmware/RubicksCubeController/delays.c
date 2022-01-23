/*
 * delays.c
 *
 * Created: 24/07/2013 14:21:44
 *  Author: Renan
 */ 

#include "delays.h"


void delay_1us(){
	_delay_us(1);
}

void delay_10us(){
	_delay_us(10);
}



void delay_1ms(){
	_delay_ms(1);
}

void delay_10ms(){
	_delay_ms(10);
}

void delay_100ms(){
	_delay_ms(100);
}

void delay_500ms(){
	_delay_ms(500);
}

void delay_ms(int delay){
	while( delay > 0 ){
		_delay_ms(1);
		delay--;
	}
}