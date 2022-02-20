/*
 * ServoPWM.c
 *
 * Created: 2/19/2022 6:24:59 PM
 *  Author: Renan
 */ 

#include "ServoPWM.h"

uint8_t ServoPWM_ISR(
	ServoPWM * const serv_ptr,
	PortPin const * const portPin_ptr,
	volatile uint8_t * const timer
)
{
	if(GET_PORT_BIT( (*portPin_ptr) ) == false)
	{
		SET_PORT_BIT( (*portPin_ptr) );
		serv_ptr->pulse = false;
		*timer = SERVOPWM_BEGIN_PULSE;		// based on 8us
	}
	else
	{
		if( serv_ptr->pulse == false )
		{
			serv_ptr->pulse = true;
			*timer = 255 - serv_ptr->actualPos;		// based on 8us
			return false;
		}
		
		RST_PORT_BIT( (*portPin_ptr) );
		return true;
	}
	
	if(serv_ptr->targetPos != serv_ptr->actualPos)
	{
		serv_ptr->moving = true;
		if(serv_ptr->targetPos > (serv_ptr->actualPos + serv_ptr->speed))
			serv_ptr->actualPos += serv_ptr->speed;
		else if(serv_ptr->targetPos < (serv_ptr->actualPos - serv_ptr->speed))
			serv_ptr->actualPos -= serv_ptr->speed;
		else
			serv_ptr->actualPos = serv_ptr->targetPos;
	}
	else
		serv_ptr->moving = false;
	
	return false;
}

void ServoPWM_SetTarget(ServoPWM * const servoPWM_ptr, uint8_t targetPos)
{
	servoPWM_ptr->targetPos = targetPos;
}

void ServoPWM_Init(	
	ServoPWM * const servoPWM_ptr, 
	PortPin const * const servoPin_ptr, 
	uint8_t targetPos
)
{
	PIN_MODE_OUTPUT((*servoPin_ptr));
	RST_PORT_BIT((*servoPin_ptr));
	
	servoPWM_ptr->actualPos = targetPos;
	servoPWM_ptr->targetPos = targetPos;
	servoPWM_ptr->speed = 1;
}

void ServoPWM_Move(
	ServoPWM * const serv_ptr,
	PortPin const * const pio_ptr,
	uint8_t target, uint8_t speed
)
{
	serv_ptr->targetPos = target;
	serv_ptr->speed = speed;
	serv_ptr->moving = true;
}

void ServoPWM_MoveWait(
	ServoPWM * const serv_ptr,
	PortPin const * const pio_ptr,
	uint8_t target, uint8_t speed
)
{
	serv_ptr->targetPos = target;
	serv_ptr->speed = speed;
	serv_ptr->moving = true;
	while( serv_ptr->moving == true );
}