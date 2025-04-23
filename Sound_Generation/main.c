/**
 * @file main.c
 *
 * @brief Main source code for the Sound Generation program.
 *
 * This file contains the main entry point and function definitions for the Sound Generation program.
 * It interfaces with the following:
 *	- Tiva LaunchPad Push Buttons (SW0 - SW1)
 *	- DMT-1206 Magnetic Buzzer
 *
 * To verify the pinout of the user LED, refer to the Tiva C Series TM4C123G LaunchPad User's Guide
 * Link: https://www.ti.com/lit/pdf/spmu296
 *
 * @author Daniel Garcia
 */

#include "TM4C123GH6PM.h"
#include "SysTick_Delay.h"
#include "GPIO.h"
#include "Buzzer.h"
#include "Notes.h"

#define WHOLE_NOTE_DURATION 1600  // 1 = whole note (1600ms), 4 = quarter, 8 = eighth, etc.
#define REST 0.0f

int main(void)
{
	// Initialize hardware
	SysTick_Delay_Init();
	LaunchPad_Buttons_Init();
	Buzzer_Init();

	while (1)
	{
		uint8_t buttons = Get_LaunchPad_Button_Status();

		if (buttons & 0x01)  // SW2 (PF0) pressed, start song
		{
			for (int i = 0; i < length_harryp; i++)
			{
				buttons = Get_LaunchPad_Button_Status();

				// If SW1 (PF4) is pressed, stop song
				if (buttons & 0x10)
				{
					Buzzer_Output(BUZZER_OFF);  // Turn buzzer off
					break;
				}

				int duration_ms = WHOLE_NOTE_DURATION / harryp_dur[i];
				Play_Note(harryp_notes[i], duration_ms);

				// Small pause to separate notes slightly
				SysTick_Delay1ms(duration_ms * 0.03);
			}
		}

		// Ensure buzzer is off if idle or interrupted
		Buzzer_Output(BUZZER_OFF);
	}
}
