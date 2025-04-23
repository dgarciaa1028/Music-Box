/**
 * @file Buzzer.h
 *
 * @brief Header file for the Buzzer driver.
 *
 * This file contains the function definitions for the Buzzer driver.
 * It interfaces with the following:
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

#define BUZZER1 0x10 // PC4
#define BUZZER2 0x20 // PC5

// Constant definitions for the buzzer
extern const uint8_t BUZZER_OFF;
extern const uint8_t BUZZER_ON;


/**
 * @brief Initializes the DMT-1206 Magnetic Buzzer on the EduBase board.
 *
 * This function configures the PC4 pin used by the DMT-1206 Magnetic Buzzer.
 * It enables the clock to Port C, sets PC4 as an output GPIO pin, configures PC4 to function as a GPIO pin,
 * and enables digital functionality for PC4.
 *
 * @param None
 *
 * @return None
 */
void Buzzer_Init(void);

/**
 * @brief Sets the output of the DMT-1206 Magnetic Buzzer.
 *
 * This function sets the output of the buzzer based on the value of the input, buzzer_value.
 * A bitwise AND operation (& 0xEF) is performed to mask Bit 4 of the GPIOC's DATA register
 * to preserve the state of other pins connected to Port C while keeping the buzzer pin unaffected.
 * Then, a bitwise OR operation is performed with buzzer_value to set the buzzer pin to the desired state
 * specified by buzzer_value.
 *
 * @param buzzer_value An 8-bit unsigned integer that determines the output of the buzzer. To turn off
 *                      the buzzer, set buzzer_value to 0. To turn on the buzzer, set buzzer_value to 0x10.
 *
 * @return None
 */
void Buzzer_Output(uint8_t buzzer_mask, uint8_t value);

/**
 * @brief Plays a note with the DMT-1206 Magnetic Buzzer.
 *
 * This function generates a square wave with the DMT-1206 Magnetic Buzzer to produce a note of the specified frequency and duration.
 * It calculates the period of the note in microseconds, divides it by two to get half period, and then toggles the
 * buzzer output at the half period interval for the specified duration.
 *
 * @param note The frequency of the note to play in Hz.
 *
 * @param duration The duration of the note in microseconds.
 *
 * @return None
 */
void Play_Note(uint8_t buzzer_mask, float note, int duration);
