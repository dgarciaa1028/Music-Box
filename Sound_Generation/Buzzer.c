/**
 * @file Buzzer.c
 *
 * @brief Source code for the Buzzer driver.
 *
 * This file contains the function definitions for the Buzzer driver.
 * It interfaces with the following:
 *	- Piezo Magnetic Buzzer
 *
 * To verify the pinout of the user LED, refer to the Tiva C Series TM4C123G LaunchPad User's Guide
 * Link: https://www.ti.com/lit/pdf/spmu296
 *
 * @author Daniel Garcia Aguilar, Robert Rabenkogo Eboulia, Aaron Nanas
 */

#include "Buzzer.h"

// Constant definitions for the buzzer
const uint8_t BUZZER_OFF = 0x00;
const uint8_t BUZZER_ON  = 0x10;  // PC4

void Buzzer_Init(void)
{
	// Enable the clock to Port C
	SYSCTL->RCGCGPIO |= 0x04;
	
	// Set PC4 as an output GPIO pin
	GPIOC->DIR |= 0x10;
	
	// Configure PC4 to function as a GPIO pin
	GPIOC->AFSEL &= ~0x10;
	
	// Enable digital functionality for PC4
	GPIOC->DEN |= 0x10;
}

void Buzzer_Output(uint8_t value)
{
	// Set the output of the buzzer (PC4 only)
	GPIOC->DATA = (GPIOC->DATA & ~0x10) | (value ? 0x10 : 0x00);
}

void Play_Note(float note, int duration)
{
	if (note <= 0.0f)
	{
		// Rest note — just delay for the full duration with no sound
		SysTick_Delay1ms(duration);
		return;
	}

	// Calculate the period of the note in microseconds
	int period_us = (int)(1000000.0f / note);
	
	// Calculate the half period of the note in microseconds
	int half_period_us = period_us / 2;
	
	// Without converting the duration into cycles, the higher frequencies would play for a much
	// shorter time when compared to playing lower frequencies due to the calculations above.
	// Due to this, playing based off of cycles instead means that every 'note' will play for the
	// same amount of time regardless of frequency.

	// Total duration in us
	int total_us = duration * 1000;
	
	// Number of cycles needed to match total duration
	int cycles = total_us / period_us;

	// Generate a square wave for the specified cycles
	for (int i = 0; i < cycles; i++)
	{
		Buzzer_Output(BUZZER_ON);
		SysTick_Delay1us(half_period_us);
		Buzzer_Output(BUZZER_OFF);
		SysTick_Delay1us(half_period_us);
	}
}
