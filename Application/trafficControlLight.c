/***************************************************************
 * Name of the group: Group (c)
 * Names of the members: Youssef Khaled
 *                       Hazem Mohamed
 *                       Mark Ehab
 * Date: 20/8/2023
 * Description: source file for the traffic light control
 ***************************************************************/

/* including the header file and the library for the interrupt */
#include "trafficControlLight.h"
#include <avr/interrupt.h>

/* flags to detect which led is on */
uint8 red_flag = STD_OFF;
uint8 yellow_flag = STD_OFF;
uint8 green_flag = STD_OFF;
uint8 blue_flag = STD_OFF;
/* flag to detect whether it's outside or inside the interrupt */
uint8 g_pedestrian_f = OUTSIDE_INTERRUPT;
uint8 g_was_in_the_interrupt = STD_OFF;

/* external interrupt one */
ISR( INT1_vect ){
	/* call the predestrain mode */
	PEDESTRAIN_mode();
	/* rise the flag that indicates that I entered the ISR */
	g_was_in_the_interrupt = STD_ON;
}


int main(){
	TRAFFICLIGHT_init(); /*initializing the modules */
	while(1){
		CARS_mode(); /* executing the CAR mode */
	}
}

/****************************************************************
 * Function name: TRAFFICLIGHT_init
 * Arguments: void
 * Return: void
 * Description: initializing all the peripherals that are used
 ****************************************************************/
void TRAFFICLIGHT_init(){
	LCD_init(); /* initializing the LCD */
	LED_init(); /* initializing the LEDs */
	BUTTON_init(); /* initializing the buttons */
}

/****************************************************************
 * Function name: CARS_mode
 * Arguments: void
 * Return: void
 * Description: executing the requirements of the CARs mode
 ****************************************************************/
void CARS_mode(){
	/* clearing the LCD and displaying "CAR" on the LCD */
	LCD_clearScreen();
	LCD_displayString("CAR");

/*first: */
	/* turning on the green led for five seconds */
	LED_turnOnOff(green_led, LED_ON);
	green_flag = STD_ON;
	for(uint8 i=0 ; i<MAX_ITERATIONS_FOR_100ms_DELAY ; i++){
		_delay_ms(100);
		if(g_was_in_the_interrupt){
			g_was_in_the_interrupt = STD_OFF;
			return;
		}
	}
	LED_turnOnOff(green_led, LED_OFF);
	green_flag = STD_OFF;

/*Second: */
	/* turning on the yellow led for five seconds */
	yellow_flag = STD_ON;
	LED_yellowBlink(NUM_OF_SEC);
	yellow_flag = STD_OFF;
	if(g_was_in_the_interrupt){
		g_was_in_the_interrupt = STD_OFF;
		return;
	}

/*Third: */
	/* turning on the red led for five seconds */
	LED_turnOnOff(red_led, LED_ON);
	red_flag = STD_ON;
	for(uint8 i=0 ; i<MAX_ITERATIONS_FOR_100ms_DELAY ; i++){
		_delay_ms(100);
		if(g_was_in_the_interrupt){
			g_was_in_the_interrupt = STD_OFF;
			return;
		}
	}
	LED_turnOnOff(red_led, LED_OFF);
	red_flag = STD_OFF;

/*Four: */
	/* turning on the green led for five seconds*/
	yellow_flag = STD_ON;
	LED_yellowBlink(NUM_OF_SEC);
	yellow_flag = STD_OFF;
	if(g_was_in_the_interrupt){
		g_was_in_the_interrupt = STD_OFF;
		return;
	}
}

/****************************************************************
 * Function name: clear_flags
 * Arguments: void
 * Return: void
 * Description: clearing all the flags.
 ****************************************************************/
void clear_flags(){
	red_flag = STD_OFF;
	yellow_flag = STD_OFF;
	green_flag = STD_OFF;
	blue_flag = STD_OFF;
}

/****************************************************************
 * Function name: PEDESTRAIN_mode
 * Arguments: void
 * Return: void
 * Description: executing the requirements of the pedestrain mode
 ****************************************************************/
void PEDESTRAIN_mode(){
	if(g_pedestrian_f == OUTSIDE_INTERRUPT){
		g_pedestrian_f = INSIDE_INTERRUPT;
		/* if the red led is on */
		if(STD_ON == red_flag){
			/* turning on the blue led and red led */
			LED_turnOnOff(blue_led, LED_ON);
			LED_turnOnOff(red_led, LED_ON);
			/* clearing the screen and displaying "pedestrain"*/
			LCD_clearScreen();
			LCD_displayString("pedestrain");
			_delay_ms(5000);
			/* turning of the blue led and red led */
			LED_turnOnOff(blue_led, LED_OFF);
			LED_turnOnOff(red_led, LED_OFF);
			/* clearing the LCD and displaying "CAR" */
			LCD_clearScreen();
			LCD_displayString("CAR");
			/* blinking the yellow led */
			LED_yellowBlink(NUM_OF_SEC);
			/* clearing the flags */
			clear_flags();
		/* if the green led is on */
		} else if(STD_ON == green_flag){
			/* turn off the green led */
			LED_turnOnOff(green_led, LED_OFF);
			/* blink the yellow for 5 seconds */
			LED_yellowBlink(NUM_OF_SEC);
			/* turning on the blue and red leds */
			LED_turnOnOff(blue_led, LED_ON);
			LED_turnOnOff(red_led, LED_ON);
			/* clearing the screen and displaying "pedestrain"*/
			LCD_clearScreen();
			LCD_displayString("pedestrain");
			_delay_ms(5000);
			/* turning off the blue and red leds */
			LED_turnOnOff(blue_led, LED_OFF);
			LED_turnOnOff(red_led, LED_OFF);
			/* clearing the LCD and displaying "CAR" */
			LCD_clearScreen();
			LCD_displayString("CAR");
			/* blinking the yellow led */
			LED_yellowBlink(NUM_OF_SEC);
			/* clearing the flags */
			clear_flags();
		/* if the yellow led is on */
		} else if(STD_ON == yellow_flag){
			/* blinking the yellow led */
			LED_yellowBlink(NUM_OF_SEC);
			/* turn on the blue and red leds */
			LED_turnOnOff(blue_led, LED_ON);
			LED_turnOnOff(red_led, LED_ON);
			/* clearing the screen and displaying "pedestrain"*/
			LCD_clearScreen();
			LCD_displayString("pedestrain");
			_delay_ms(5000);
			/* turning off the blue and red leds */
			LED_turnOnOff(blue_led, LED_OFF);
			LED_turnOnOff(red_led, LED_OFF);
			/* clearing the LCD and displaying "CAR" */
			LCD_clearScreen();
			LCD_displayString("CAR");
			/* blinking the yellow led */
			LED_yellowBlink(NUM_OF_SEC);
			/* clear the flags */
			clear_flags();
		}
		/* clearing the flag which indicates that I'm exiting the *
		 * interrupt.                                             */
		g_pedestrian_f = OUTSIDE_INTERRUPT;
	}
}

