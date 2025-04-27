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
#include "PWM_Clock.h"
#include "Timer_0A_Interrupt.h"
#include "PWM0_0.h"

#define SERVO_MIN_DUTY  0
#define SERVO_MAX_DUTY  7000
#define SERVO_STEP_SIZE 1

void Timer_0A_Periodic_Task(void);

static uint32_t Timer_0A_ms_elapsed = 0;
static uint16_t servo_duty_cycle = SERVO_MIN_DUTY;
static int servo_direction = 1;


int main(void)
{
	// Initialize hardware
	SysTick_Delay_Init();
	LaunchPad_Buttons_Init();
	Buzzer_Init(); // PC4
	PMOD_ENC_Init();
	PWM_Clock_Init();                    // Must be before PWM0_0_Init
	PWM0_0_Init(15625, SERVO_MIN_DUTY);  // 20ms period at 781.25kHz (from /64 clock)
	Timer_0A_Interrupt_Init(&Timer_0A_Periodic_Task); // Start servo control

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

      SysTick_Delay1ms(100);
		
	}
}

void Timer_0A_Periodic_Task(void)
{
    Timer_0A_ms_elapsed++;

    if ((Timer_0A_ms_elapsed % 1) == 0)
    {
        servo_duty_cycle += (servo_direction * SERVO_STEP_SIZE);

        if (servo_duty_cycle >= SERVO_MAX_DUTY)
        {
            servo_duty_cycle = SERVO_MAX_DUTY;
            servo_direction = -1;
        }
        else if (servo_duty_cycle <= SERVO_MIN_DUTY)
        {
            servo_duty_cycle = SERVO_MIN_DUTY;
            servo_direction = 1;
        }

        PWM0_0_Update_Duty_Cycle(servo_duty_cycle);
    }
}
