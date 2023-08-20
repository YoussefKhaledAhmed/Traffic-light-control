/***************************************************************
 * Name of the group: Group (c)
 * Names of the members: Youssef Khaled
 *                       Hazem Mohamed
 *                       Mark Ehab
 * Date: 20/8/2023
 * Description: header file for the LED
 ***************************************************************/

#ifndef LED_H_
#define LED_H_

/* included library for dealy and dio header file to access the pins */
#include "dio.h"
#include <util/delay.h>

/* enum for labeling the leds */
typedef enum{
	green_led , yellow_led , red_led , blue_led
} led;

/* enum for the leds state */
typedef enum{
	LED_OFF , LED_ON
} led_status;

/* functions prototypes */
void LED_init();/* initializing the direction and turning off all the leds */
void LED_turnOnOff(uint8 led , uint8 status); /* turning on or off the passed led */
void LED_yellowBlink(uint8 ); /* blinking the yellow led */

#endif /* LED_H_ */
