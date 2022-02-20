/*
 * RubicksCubeController.h
 *
 * Created: 2/20/2022 3:08:12 PM
 *  Author: Renan
 *
 * Portas Utilizadas
 *   PB 4:6, PE 2:3, PD 0:7		Camera
 *   PG 0:2						Servos
 *   PC 0:3						Botoes
 *
 */ 


#ifndef RUBICKSCUBECONTROLLER_H_
#define RUBICKSCUBECONTROLLER_H_

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "delays.h"
#include "UART.h"
#include "Bits.h"
#include "SD.h"
#include "PortPin.h"
#include "ServoPWM.h"
#include "EEPROM.h"

#define ServoDelay (255-120)	// 16,6ms
#define sleep _delay_us(5);

// Botoes
#define buttonRed		0x04
#define buttonGreen		0x08
#define buttonBlue		0x10
#define buttonYellow	0x20


#endif /* RUBICKSCUBECONTROLLER_H_ */