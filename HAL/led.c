/***************************************************************
 * Name of the group: Group (c)
 * Names of the members: Youssef Khaled
 *                       Hazem Mohamed
 *                       Mark Ehab
 * Date: 20/8/2023
 * Description: source file for the LED
 ***************************************************************/
#include "led.h"

/* configurations of the red, green, blue, yellow leds */
DIO_PinConfiguration RED_LED = {PORTB_ID , PIN7_ID};
DIO_PinConfiguration GREEN_LED = {PORTA_ID , PIN4_ID};
DIO_PinConfiguration BLUE_LED = {PORTA_ID , PIN5_ID};
DIO_PinConfiguration YELLOW_LED = {PORTA_ID , PIN6_ID};

/*****************************************************************
 * Function name: LED_init
 * Arguments: void
 * Return: void
 * Description: initializing all the led pins direction and value
 *****************************************************************/
void LED_init(){
	/* configurations for the led pins*/
	DIO_setupPinDirection(&RED_LED, PIN_OUTPUT);
	DIO_setupPinDirection(&GREEN_LED, PIN_OUTPUT);
	DIO_setupPinDirection(&YELLOW_LED, PIN_OUTPUT);
	DIO_setupPinDirection(&BLUE_LED, PIN_OUTPUT);
	/* turning off all the leds */
	DIO_writePin(&BLUE_LED, LOGIC_LOW);
	DIO_writePin(&GREEN_LED, LOGIC_LOW);
	DIO_writePin(&YELLOW_LED, LOGIC_LOW);
	DIO_writePin(&RED_LED, LOGIC_LOW);

}


/*****************************************************************
 * Function name: LED_turnOnOff
 * Arguments: led , status
 * Return: void
 * Description: turning on or off the passed led
 *****************************************************************/
void LED_turnOnOff(uint8 led , uint8 status){
	/* switching over the leds to turn on or off the passed one*/
	switch(led){
/*if yellow:*/
	case yellow_led:
		/* if LED_ON is passed then turn the led on */
		if(LED_ON == status){
			DIO_writePin(&YELLOW_LED, LOGIC_HIGH);
		/* if LED_OFF is passed then turn the led off */
		} else if(LED_OFF == status){
			DIO_writePin(&YELLOW_LED, LOGIC_LOW);
		}
		break;
	case red_led:
		/* if LED_ON is passed then turn the led on */
		if(LED_ON == status){
			DIO_writePin(&RED_LED, LOGIC_HIGH);
		/* if LED_OFF is passed then turn the led off */
		} else if(LED_OFF == status){
			DIO_writePin(&RED_LED, LOGIC_LOW);
		}
		break;
	case green_led:
		/* if LED_ON is passed then turn the led on */
		if(LED_ON == status){
			DIO_writePin(&GREEN_LED, LOGIC_HIGH);
		/* if LED_OFF is passed then turn the led off */
		} else if(LED_OFF == status){
			DIO_writePin(&GREEN_LED, LOGIC_LOW);
		}
		break;
	case blue_led:
		/* if LED_ON is passed then turn the led on */
		if(LED_ON == status){
			DIO_writePin(&BLUE_LED, LOGIC_HIGH);
		/* if LED_OFF is passed then turn the led off */
		} else if(LED_OFF == status){
			DIO_writePin(&BLUE_LED, LOGIC_LOW);
		}
		break;
	}
}

/*********************************************************************
 * Function name: LED_yellowBlink
 * Arguments: number of seconds
 * Return: void
 * Description: blinking the yellow led for the passed number of secs
 *********************************************************************/
void LED_yellowBlink(uint8 numOfSeconds){
	for(uint8 i=0 ; i<numOfSeconds ; i++){
		DIO_writePin(&YELLOW_LED, LOGIC_HIGH);
		_delay_ms(500);
		DIO_writePin(&YELLOW_LED, LOGIC_LOW);
		_delay_ms(500);
	}
}

/*****************************************************************
 * Function name: LED_allOff
 * Arguments: void
 * Return: void
 * Description: turning off all the leds
 *****************************************************************/
void LED_allOff(){
	DIO_writePin(&YELLOW_LED, LOGIC_LOW);
	DIO_writePin(&RED_LED, LOGIC_LOW);
	DIO_writePin(&GREEN_LED, LOGIC_LOW);
	DIO_writePin(&BLUE_LED, LOGIC_LOW);

}
