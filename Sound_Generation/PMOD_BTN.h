/**
 * @file PMOD_BTN_Interrupt.h
 *
 * @brief Header file for the PMOD_BTN_Interrupt driver.
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

#include "TM4C123GH6PM.h"

/**
 * @brief Initializes interrupts for the PMOD BTN module using Port A.
 *
 * This function initializes interrupts for the PMOD BTN module
 * connected to the following pins:
 * 	- BTN0 (PA2)
 *	- BTN1 (PA3)
 *	- BTN2 (PA4)
 *	- BTN3 (PA5)
 *
 * It configures the specified pins to trigger interrupts on rising edges.
 * When an interrupt occurs, the provided task function is executed with the current button status.
 * Interrupt priority is set to 3 for GPIO Port A.
 *
 * @param task A pointer to the user-defined function to be executed upon button interrupts.
 *
 * @return None
 */
void PMOD_BTN_Init(void);

/**
 * @brief Reads the current status of the PMOD BTN module.
 *
 * This function reads the current status of the PMOD BTN module connected to Port A.
 * It returns the button status as an 8-bit unsigned integer, where each bit represents
 * the state of a specific button.
 *
 * @return An 8-bit unsigned integer representing the status of the PMOD BTN module.
 */
uint8_t PMOD_BTN_Read(void);