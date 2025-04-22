/**
 * @file main.c
 *
 * @brief Main source code for the Sound Generation program.
 *
 * This file contains the main entry point and function definitions for the Sound Generation program.
 * It interfaces with the following:
 *	- EduBase Board LEDs (LED0 - LED3)
 *	- EduBase Board Push Buttons (SW2 - SW5)
 *	- DMT-1206 Magnetic Buzzer
 *
 * To verify the pinout of the user LED, refer to the Tiva C Series TM4C123G LaunchPad User's Guide
 * Link: https://www.ti.com/lit/pdf/spmu296
 *
 * @author Aaron Nanas
 */
 
#include "TM4C123GH6PM.h"
#include "SysTick_Delay.h"
#include "GPIO.h"
#include "Buzzer.h"

int main(void)
{
	// Initialize the SysTick Timer used to provide a blocking delay function
	SysTick_Delay_Init();
	
	// Initialize the LEDs on the EduBAse board (Port B)
	EduBase_LEDs_Init();
	
	// Initialize the buttons (SW2-SW5) on the EduBase board (Port D)
	EduBase_Button_Init();
	
	// Initialize the DMT-1206 Magnetix Buzzer (Port C)
	Buzzer_Init();
	
	const double notes[7] = 
	{
		C4_NOTE,
		D4_NOTE,
		E4_NOTE,
		F4_NOTE,
		G4_NOTE,
		A4_NOTE,
		B4_NOTE
	};
	
	const double duration[7] = 
	{
		50,
		50,
		50,
		100,
		100,
		100,
		150
	};
	
	while(1)
	{
		// We will want to replace this with the encoder module to select a song
		uint8_t edubase_button_status = Get_EduBase_Button_Status();
		
		if (edubase_button_status == 0x01)
		{
			Buzzer_Output(BUZZER_ON);
			SysTick_Delay1us(1135);
			Buzzer_Output(BUZZER_OFF);
			SysTick_Delay1us(1135);
		/*
			for (int i = 0; i < 7; i++)
			{
				Play_Note(notes[i], 100);
			}
			
			for (int i = 0, j = 0; i < 7, j < 7; i++, j++)
			{
				Play_Tune(notes[i], duration[j]);
			}
		*/
		}
		else
		{
			Buzzer_Output(BUZZER_OFF);
		}
	}
}
