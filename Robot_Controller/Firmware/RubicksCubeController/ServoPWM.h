/*
 * ServoPWM.h
 *
 * Created: 2/19/2022 4:41:33 PM
 *  Author: Renan
 */ 


#ifndef SERVOPWM_H_
#define SERVOPWM_H_

#include "PortPin.h"
#include <stdbool.h>

#define SERVOPWM_BEGIN_PULSE (255-60)

/**
 struct Servo PWM
*/
typedef struct 
{
	volatile uint8_t moving:1;
	uint8_t pulse:1;
	uint8_t speed:6;
	uint8_t actualPos;
	uint8_t targetPos;
} ServoPWM;

uint8_t ServoPWM_ISR(	ServoPWM * const servoPWM_ptr, 
						PortPin const * const portPin_ptr, 
						volatile uint8_t * const timer
					);

void ServoPWM_SetTarget(ServoPWM * const servoPWM_ptr, 
						uint8_t targetPos
						);

void ServoPWM_Init(	ServoPWM * const servoPWM_ptr, 
					PortPin const * const servoPin_ptr, 
					uint8_t targetPos
					);

void ServoPWM_Move(	ServoPWM * const serv_ptr,
					PortPin const * const pio_ptr,
					uint8_t target, uint8_t speed
					);
				
void ServoPWM_MoveWait(	ServoPWM * const serv_ptr, 
						PortPin const * const pio_ptr, 
						uint8_t target, uint8_t speed
						);

#endif /* SERVOPWM_H_ */