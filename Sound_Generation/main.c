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

int main(void)
{
	// Initialize the SysTick Timer used to provide a blocking delay function
	SysTick_Delay_Init();
	
	// Initialize the Tiva LaunchPad buttons (SW0 and SW1)
	LaunchPad_Buttons_Init();
	
	// Initialize the DMT-1206 Magnetix Buzzer (Port C)
	Buzzer_Init();
	
	// Make arrays containing notes and durations of notes in a song
	float top_notes[] = {
    C4, C4, G4, G4, A4, A4, G4,  // "Twinkle twinkle little star"
    F4, F4, E4, E4, D4, D4, C4,  // "How I wonder what you are"
    G4, G4, F4, F4, E4, E4, D4,  // "Up above the world so high"
    G4, G4, F4, F4, E4, E4, D4,  // "Like a diamond in the sky"
    C4, C4, G4, G4, A4, A4, G4,  // Repeats first line
    F4, F4, E4, E4, D4, D4, C4   // Repeats second line
	};

	int length = 42;
	const int twinkle_durations[] = {
    400, 400, 400, 400, 400, 400, 800,
    400, 400, 400, 400, 400, 400, 800,
    400, 400, 400, 400, 400, 400, 800,
    400, 400, 400, 400, 400, 400, 800,
    400, 400, 400, 400, 400, 400, 800,
    400, 400, 400, 400, 400, 400, 800
	};
	
	while(1)
	{
		// We will want to replace this with the encoder module to select a song
		uint8_t launchpad_button_status = Get_LaunchPad_Button_Status();
		
		if (launchpad_button_status & 0x01)
		{
			for (int i = 0; i < length; i++)
			{
				Play_Note(BUZZER1, top_notes[i], twinkle_durations[i]);
			} 
		}
		else if (launchpad_button_status & 0x10)
		{
			for (int i = 0; i < length; i++)
			{
				Play_Note(BUZZER1, top_notes[i], twinkle_durations[i]);
			} 
		}
		else
		{
			Buzzer_Output(BUZZER1, BUZZER_OFF);
			Buzzer_Output(BUZZER2, BUZZER_OFF);
		}
	}
}
