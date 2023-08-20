/*********************************************************************
 * Name of the group: Group (c)
 * Names of the members: Youssef Khaled
 *                       Hazem Mohamed
 *                       Mark Ehab
 * Date: 20/8/2023
 * Description: source file for the button where the INT1 connected
 *********************************************************************/
#include "button.h"

/* configuration of the button */
DIO_PinConfiguration button = {PORTD_ID , PIN3_ID};

/*****************************************************************
 * Function name: BUTTON_init
 * Arguments: void
 * Return: void
 * Description: initializing the direction of the pin to input
 *              , enabling the internal pull up resistor, and
 *              enabling the global interrupt bit and the external
 *              interrupt 1 bit.
 *****************************************************************/
void BUTTON_init(){
	DIO_setupPinDirection(&button, PIN_INPUT); /* configuring the pin to be input*/
	DIO_pullUpResistorEnable(&button); /*enabling the internal pull up */
	EXTI_int1_init(); /* initializing the external interrupt 1 */
	EXTI_init(); /* enabling the global interrupt (I-bit) */
}
