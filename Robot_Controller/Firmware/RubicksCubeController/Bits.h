/*
 * //////////////////////////////////////////////
 *
 * Manipulacao de Bits
 *
 * //////////////////////////////////////////////
 *
 * Created: 2/13/2013 12:53:01 PM
 *  Author: Renan
 */

#ifndef BITS_H_
#define BITS_H_

#define SETBIT(port, pin) port|=(1<<pin)
#define RSTBIT(port, pin) port&=~(1<<pin)
#define GETBIT(port, pin) (port&(1<<pin))

/**
  Structure for PORT
  PortOut , DDR, PortIn, pin
*/
typedef struct PORT 
{
	volatile uint8_t * portOut;
	volatile uint8_t * ddr;
	volatile uint8_t * portIn;
	uint8_t pin;
}PORT;




#endif /* BITS_H_ */
