/**
 * @file PMOD_BTN_Interrupt.c
 *
 * @brief Source file for the PMOD_BTN_Interrupt driver.
 *
 * This file contains the function definitions for the PMOD_BTN_Interrupt driver.
 * It interfaces with the PMOD BTN module. The following pin is used:
  	- PMOD BTN0 (PA2)
		- PMOD BTN0 (PA3)
		- PMOD BTN0 (PA4)
		- PMOD BTN0 (PA5)
 *
 * It configures the pins to trigger interrupts on rising edges. The PMOD BTN
 * push buttons operate in an active high configuration.
 *
 * @author Daniel Garcia Aguilar, Robert Rabenkogo Eboulia, Aaron Nanas
 */

#include "PMOD_BTN.h"

void PMOD_BTN_Init(void)
{
	// Enable the clock to Port A
	SYSCTL->RCGCGPIO |= 0x01;
	
	// 0011 1100 Set to input
	GPIOA->DIR &= ~0x3C;
	
	// Clear to set an input GPIO pin
	GPIOA->AFSEL &= ~0x3C;
	
	// Enablge Digital Enabler
	GPIOA->DEN |= 0x3C;
	
	// Pull Down Resistor
	GPIOA->PDR |= 0x3C;
	
}

uint8_t PMOD_BTN_Read(void)
{
	// reads and returns status of push button
	uint8_t pmod_btn_state = GPIOA->DATA & 0x3C;
	
	return pmod_btn_state;
}

