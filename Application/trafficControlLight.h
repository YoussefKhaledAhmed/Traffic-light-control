/***************************************************************
 * Name of the group: Group (c)
 * Names of the members: Youssef Khaled
 *                       Hazem Mohamed
 *                       Mark Ehab
 * Date: 20/8/2023
 * Description: Header file for the traffic light control
 ***************************************************************/


#ifndef TRAFFICCONTROLLIGHT_H_
#define TRAFFICCONTROLLIGHT_H_

/* files to include */
#include "button.h" /* header file of the button module */
#include "led.h" /* header for the led module */
#include "lcd.h" /* header for the LCD module */
#include <util/delay.h> /* header to use the delay functions */

#define NUM_OF_SEC 5 /* number of seconds to blink */
#define INSIDE_INTERRUPT 1 /* indication that I'm inside the ISR */
#define OUTSIDE_INTERRUPT 0 /*indication that I'm outside the ISR */
#define MAX_ITERATIONS_FOR_100ms_DELAY 50 /*which means this */

extern DIO_PinConfiguration RED_LED; /* configurations for red led*/
extern DIO_PinConfiguration GREEN_LED; /* configurations for green led*/
extern DIO_PinConfiguration YELLOW_LED; /* configurations for yellow led*/
extern DIO_PinConfiguration BLUE_LED; /* configurations for blue led */


void TRAFFICLIGHT_init(); /* to initialize all the */
void CARS_mode(); /*to execute the CARs mode */
void clear_flags(); /* clear all the flags */
void PEDESTRAIN_mode(); /*to execute the predestrain mode*/



#endif /* TRAFFICCONTROLLIGHT_H_ */
