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
#include "PMOD_ENC.h"


int main(void)
{
	// Initialize hardware
	SysTick_Delay_Init();
	LaunchPad_Buttons_Init();
	Buzzer_Init(); // PC4
	PMOD_ENC_Init();
	/*
		A = PD0, B = PD1, BTN = PD2, SWT = PD3, 5th pin = GND, 6th pin = Vcc
	*/
	
	uint8_t last_state = PMOD_ENC_Get_State();
  int current_song_index = 0;
  int last_song_index = -1;
  const int num_songs = 4; // Change this when you add another song

	while (1)
	{
		uint8_t state = PMOD_ENC_Get_State();
    int direction = PMOD_ENC_Get_Rotation(state, last_state);
    last_state = state;

    if (direction == 1)
			current_song_index = (current_song_index + 1) % num_songs;
    else if (direction == -1)
       current_song_index = (current_song_index - 1 + num_songs) % num_songs;

     if (current_song_index != last_song_index)
			 {
					last_song_index = current_song_index;

          switch (current_song_index)
          {
            case 0: Play_Tetris(); break; // starts immediately playing tetris when resetn 
            case 1: Play_HarryPotter(); break;
            case 2: Play_Pirates(); break;
						case 3: Play_PinkPanther(); break; // to add another song, keep same format
          }
        }

      SysTick_Delay1ms(100);  // debounce
		
	}
}
