/**
 * @file main.c
 *
 * @brief main program for a button driven music box. We can select between 4 tunes, each
 * assotiated with a different button on the PMOD button module. An ISR is set up using 
 * Timer 0A in order to sweep the servo as music is playing. The PMOD buttons use polling
 * to know when a button is pushed, while the servo motor uses Timers to execute an ISR 
 * concurrently with the while loop in the main function. 
 *
 * Each PMOD-BTN press immediately starts its associated tune.
 * A single 1 kHz Timer0A ISR handles the servo sweep.
 * PMOD BTN Pinout: BTN0(PA2), BTN1(PA3), BTN2(PA4), BTN3(PA5), PIN5(GND) PIN6(VCC)
 * Buzzer Output: PC4
 * Servo Motor Output: PB6
 *
 * @author Daniel Garcia Aguilar, Robert Rabenkogo Eboulia
 */

#include "TM4C123GH6PM.h"
#include "SysTick_Delay.h"
#include "GPIO.h"
#include "Buzzer.h"
#include "Notes.h"
#include "PMOD_BTN.h"
#include "PWM_Clock.h"
#include "Timer_0A_Interrupt.h"
#include "PWM0_0.h"

// Servo sweep parameters
#define SERVO_MIN_DUTY 0
#define SERVO_MAX_DUTY 5000 // restrict sweep so that it faces the front most of the time
#define SERVO_STEP_SIZE 1 // increases duty cycle by this value in order to make the sweep 'slow'

// globals for servo control
static uint16_t servo_duty = SERVO_MIN_DUTY; // Initial duty cycle
static int servo_dir = 1; // tracks which direction motor is sweeping, 1 will increase, and -1 will decrese duty cycle
static uint32_t ms_elapsed = 0; // For Timer use

// forward declarations
void Timer_0A_Periodic_Task(void);

int main(void)
{
  SysTick_Delay_Init(); // for all delays
  LaunchPad_Buttons_Init(); // For debugging
  Buzzer_Init(); // PC4 buzzer output
	PMOD_BTN_Init(); // PA2-PA5 button input

  PWM_Clock_Init();
	
	// The period constant for the PWM signal that determines the PWM signal's frequency,
	// Duty Cycle as a percentage of the period constant
  PWM0_0_Init(15625, SERVO_MIN_DUTY); // 20 ms period, 0%

  Timer_0A_Interrupt_Init(&Timer_0A_Periodic_Task);   // ISR for servo sweeping

  while (1)
  {
    uint8_t btn_state = PMOD_BTN_Read(); // initialize variable for button read
		
		// dispatch to the appropriate tune
		switch (btn_state)
		{
			// BTN0 (PA2)
			case 0x04:  
			{
				Play_Tetris();     
				break;
			}
			// BTN1 (PA3)
			case 0x08:  
			{
				Play_HarryPotter();
				break;
			}
			// BTN 2 (PA4)
			case 0x10:  
			{
				Play_Pirates(); 
				break;  // PA4
			}
			// BTN 3 (PA5)
			case 0x20:  
			{
				Play_mario();    
				break;  // PA5
			}
			// No button is pressed
			default:
			{
				break;
			}
		}
		SysTick_Delay1ms(500);
  }
}


// Timer0A ISR: slowly sweep the servo during main
void Timer_0A_Periodic_Task(void)
{
  ms_elapsed++; // counter

  // every tick, move the servo one step back/forth depending on servo_dir
	// for -1, will subtract a step untill duty cycle = 0,
	// for 1, will add a step until duty cycle = 5000
  servo_duty += servo_dir * SERVO_STEP_SIZE;
	
	// Once servo_duty reached 5000, will set direction to -1
  if (servo_duty >= SERVO_MAX_DUTY)
	{
		servo_duty = SERVO_MAX_DUTY;
		servo_dir = -1; 
	}
	// Once servo_duty reached 0, will set direction to 1
  else if (servo_duty <= SERVO_MIN_DUTY)
	{
		servo_duty = SERVO_MIN_DUTY;
		servo_dir = 1;
	}
	
  PWM0_0_Update_Duty_Cycle(servo_duty); // Updates duty cycle for smooth, slow sweep
}
