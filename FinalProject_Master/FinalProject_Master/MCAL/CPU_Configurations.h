/*
 * CPU_Configurations.h
 *
 * Created: 8/7/2021 10:22:13 PM
 *  Author: karim
 */ 


#ifndef CPU_CONFIGURATIONS_H_
#define CPU_CONFIGURATIONS_H_

/*Micro-Controller CPU Configuration*/
#undef F_CPU                // Undefined internal oscillator
#define F_CPU 16000000      // Defined external oscillator
#include <avr/io.h>         // Defined Input/Output for this MC
#include <avr/interrupt.h>  // Defined interrupts for AVR controller
#include <util/delay.h>     // Defined built-in delay function
#include "BIT_MATH.h"
#include "DIO.h"
#endif /* CPU_CONFIGURATIONS_H_ */