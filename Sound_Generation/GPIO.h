/**
 * @file GPIO.h
 *
 * @brief Header file for the GPIO driver.
 *
 * This file contains the function definitions for the GPIO driver.
 * It interfaces with the following:
 *  - User LED (RGB) Tiva C Series TM4C123G LaunchPad
 *	- EduBase Board LEDs (LED0 - LED3)
 *	- EduBase Board Push Buttons (SW2 - SW5)
 *
 * To verify the pinout of the user LED, refer to the Tiva C Series TM4C123G LaunchPad User's Guide
 * Link: https://www.ti.com/lit/pdf/spmu296
 *
 * @author Daniel Garcia Aguilar, Robert Rabenkogo Eboulia
 */

#include "TM4C123GH6PM.h"
#include "SysTick_Delay.h"

// Constant definitions for the user LED (RGB) colors
extern const uint8_t RGB_LED_OFF;
extern const uint8_t RGB_LED_RED;
extern const uint8_t RGB_LED_BLUE;
extern const uint8_t RGB_LED_GREEN;

/**
 * @brief The RGB_LED_Init function initializes the RGB LED (PF1 - PF3)
 *
 * This function initializes the following RGB LED pins, configures the digital functionality for the pins,
 * and sets the direction of the pins as output. The RGB LED is off by default upon initialization.
 *  - LED_R     (PF1)
 *  - LED_B     (PF2)
 *  - LED_G     (PF3)
 *
 * @param None
 *
 * @return None
 */
void RGB_LED_Init(void);

/**
 * @brief The RGB_LED_Output function sets the output of the RGB LED.
 *
 * This function sets the output of the RGB LED based on the value of the input, led_value.
 * A bitwise AND operation (& 0xF1) is performed to mask the Bits 1 to 3 of the GPIOF's DATA register
 * to preserve the state of other pins connected to Port F while keeping the RGB LED pins unaffected.
 * Then, a bitwise OR operation is performed with led_value to set the RGB LED pins to the desired state
 * specified by led_value.
 *
 * @param led_value An 8-bit unsigned integer that determines the output of the RGB LED. To turn off
 *                  the RGB LED, set led_value to 0. The following values determine the color of the RGB LED:
 *
 *  Color       LED(s)   led_value
 *  Off         ---         0x00
 *  Red         R--         0x02
 *  Blue        -B-         0x04
 *  Green      	--G         0x08
 *
 * @return None
 */
void RGB_LED_Output(uint8_t led_value);

/**
 * @brief The RGB_LED_Status function indicates the status of the RGB LED
 * located at pins PF1, PF2, and PF3.
 *
 * @param None
 *
 * @return uint8_t The value representing the status of the RGB LED.
 *
 *  Color       LED(s)   led_value
 *  Off         ---         0x00
 *  Red         R--         0x02
 *  Blue        -B-         0x04
 *  Green       --G         0x08
 *
 */
uint8_t RGB_LED_Status(void);

/**
 * @brief The LaunchPad_Button_Init function initializes the LaunchPads buttons (SW0 & SW1).
 *
 * This function initializes the LaunchPad's buttons connected to pins PF0 and PF4.
 * It enables digital functionality and configures the pins as GPIO input pins.
 *
 * @param None
 *
 * @return None
 */
void LaunchPad_Buttons_Init(void);

/**
 * @brief The Get_LaunchPad_Button_Status reads the status of the LaunchPad Board buttons (SW0 - SW1) and returns it.
 *
 * This function reads the status of the LaunchPad's Board buttons connected to pins PF0 and PF4.
 * It indicates whether or not the buttons are pressed and returns the status.
 * A bitwise AND operation (& ~0x11) is performed to mask the unused bits in the data register.
 *
 * @param None
 *
 * @return Indicates the status of the buttons. 
 */
uint8_t Get_LaunchPad_Button_Status(void);
