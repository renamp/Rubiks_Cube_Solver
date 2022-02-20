/*
 * PortPin.h
 *
 * Created: 2/19/2022 2:53:58 PM
 *  Author: Renan
 */ 


#ifndef PORTPIN_H_
#define PORTPIN_H_

#include <avr/io.h>

#if defined (__AVR_ATmega328P__)
	#define PORTPIN_DDR_OFFSET -1
	#define PORTPIN_PIN_OFFSET -2
#else
	#define PORTPIN_DDR_OFFSET -1
	#define PORTPIN_PIN_OFFSET -2
#endif

typedef struct
{
	volatile uint8_t * const port;
	const uint8_t pin;
} PortPin;

/*
  Uses Struct PortPIn as input 
*/

#define SET_PORT_BIT(PIN) (*PIN.port |= (1 << PIN.pin))
#define RST_PORT_BIT(PIN) (*PIN.port &= ~(1 << PIN.pin))

#define SET_PIN_BIT(PIN) (*(PIN.port + PORTPIN_PIN_OFFSET) |= (1 << PIN.pin))
#define RST_PIN_BIT(PIN) (*(PIN.port + PORTPIN_PIN_OFFSET) &= ~(1 << PIN.pin))

#define PIN_MODE_INPUT(PIN) (*(PIN.port + PORTPIN_DDR_OFFSET) &= ~(1 << PIN.pin))
#define PIN_MODE_OUTPUT(PIN) (*(PIN.port + PORTPIN_DDR_OFFSET) |= (1 << PIN.pin))

#define GET_PORT_BIT(PIN) (*(PIN.port) & (1 << PIN.pin))
#define GET_INPUT_BIT(PIN) (*(PIN.port + PORTPIN_PIN_OFFSET) & (1 << PIN.pin))

#endif /* PORTPIN_H_ */