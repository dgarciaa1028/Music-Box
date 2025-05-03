/**
 * @file GPIO.c
 *
 * @brief Source code for the GPIO driver.
 *
 * This file contains the function definitions for the GPIO driver.
 * It interfaces with the following:
 *  - User LED (RGB) Tiva C Series TM4C123G LaunchPad
 *
 * To verify the pinout of the user LED, refer to the Tiva C Series TM4C123G LaunchPad User's Guide
 * Link: https://www.ti.com/lit/pdf/spmu296
 *
 * @author Daniel Garcia Aguilar, Robert Rabenkogo Eboulia
 */

#include "GPIO.h"

// Constant definitions for the user LED (RGB) colors
const uint8_t RGB_LED_OFF 		= 0x00;
const uint8_t RGB_LED_RED 		= 0x02;
const uint8_t RGB_LED_BLUE 		= 0x04;
const uint8_t RGB_LED_GREEN 	= 0x08;


void RGB_LED_Init(void)
{
	// Enable the clock to Port F
	SYSCTL->RCGCGPIO |= 0x20;

	// Set PF1, PF2, and PF3 as output GPIO pins
	GPIOF->DIR |= 0x0E;
	
	// Configure PF1, PF2, and PF3 to function as GPIO pins
	GPIOF->AFSEL &= ~0x0E;
	
	// Enable digital functionality for PF1, PF2, and PF3
	GPIOF->DEN |= 0x0E;
	
	// Initialize the output of the RGB LED to zero
	GPIOF->DATA &= ~0x0E;
}

void RGB_LED_Output(uint8_t led_value)
{
	// Set the output of the RGB LED
	GPIOF->DATA = (GPIOF->DATA & 0xF1) | led_value;
}

uint8_t RGB_LED_Status(void)
{
	// Assign the value of Port F to a local variable
	// and only read the values of the following bits: 3, 2, and 1
	// Then, return the local variable's value
	uint8_t RGB_LED_Status = GPIOF->DATA & 0x0E;
	return RGB_LED_Status;
}


void LaunchPad_Buttons_Init(void)
{
	// Enable Clock to Port F
	SYSCTL->RCGCGPIO |= 0x20;
	
	// Unlock PF0
	GPIOF->LOCK = 0x4C4F434B;
	GPIOF->CR |= 0x11;
	
	// Set PF4(SW1) and PF0(SW2) as inputs
	GPIOF->DIR &= ~0x11;
	
	// Disable alternate functions
	GPIOF->AFSEL &= ~0x11;
	
	// Enable pull-up resistor (buttons are active low)
	GPIOF->PUR |= 0x11;
	
	// Enable Digital Functionaloty
	GPIOF->DEN |= 0x11;
}

uint8_t Get_LaunchPad_Button_Status(void)
{
	// Return pressed buttons as bits (bit 4 = SW1, bit 0 = SW2)
	// Active low so we invert the bits
	return (~GPIOF->DATA) & 0x11;
}

	