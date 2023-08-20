/******************************************************
 * Name: Youssef Khaled Ahmed
 * Date: 19/8/2023
 * Description: source file for external interrupt
 ******************************************************/
#include <avr/io.h>
#include "external_interrupt.h"


/*****************************************************************
 * Function name: EXTI_init
 * Arguments: void
 * Return: void
 * Description: setting the I-bit (i.e., global interrupt bit).
 *****************************************************************/
void EXTI_init(void){
	SET_BIT(SREG , GLOBAL_INTERRUPT_BIT_NUM);
}


/*****************************************************************
 * Function name: EXTI_int0_init
 * Arguments: void
 * Return: void
 * Description: 1. disabling the global interrupt
 *              2. setting the values of ISC00 and ISC01 to
 *                 initialize the desired mode of the interrupt
 *              3. setting the INT0 bit in the GICR to enable
 *                 the external interrupt 0.
 *****************************************************************/
void EXTI_int0_init(void){
	CLEAR_BIT(SREG , GLOBAL_INTERRUPT_BIT_NUM); /* disabling the global interrupt */
	/* clearing ISC00 and ISC01 by using (MCUCR & (0xFC)) and applying OR  *
	 * operation with the mode that is defined in the header file.         */
	uint8 MCUCR_replaceValue = (MCUCR & (0xFC)) | (INT0_MODE);
	MCUCR = MCUCR_replaceValue;
	/* setting the INT0 bit in the GICR register */
	SET_BIT(GICR , INT0);
}

/*****************************************************************
 * Function name: EXTI_int1_init
 * Arguments: void
 * Return: void
 * Description: 1. disabling the global interrupt
 *              2. setting the values of ISC10 and ISC11 to
 *                 initialize the desired mode of the interrupt
 *              3. setting the INT1 bit in the GICR to enable
 *                 the external interrupt 1.
 *****************************************************************/
void EXTI_int1_init(void){
	CLEAR_BIT(SREG , GLOBAL_INTERRUPT_BIT_NUM);/* disabling the global interrupt    */
	/* clearing ISC10 and ISC11 by using (MCUCR & (0xF3)) and applying OR           *
	 * operation with the mode that is defined in the header file but shifted       *
	 * since the ISC10 and ISC11 bits are bits number 2 and 3 in the MCUCR register */
	uint8 MCUCR_replaceValue = (MCUCR & (0xF3)) | (INT1_MODE<<2);
	MCUCR = MCUCR_replaceValue;
	/* setting the INT1 bit in the GICR register */
	SET_BIT(GICR , INT1);
}


/*****************************************************************
 * Function name: EXTI_int2_init
 * Arguments: void
 * Return: void
 * Description: 1. disabling the global interrupt
 *              2. setting the values of ISC2 to
 *                 initialize the desired mode of the interrupt
 *              3. setting the INT2 bit in the GICR to enable
 *                 the external interrupt 2.
 *****************************************************************/
void EXTI_int2_init(void){
	CLEAR_BIT(SREG , GLOBAL_INTERRUPT_BIT_NUM); /* disabling the global interrupt */
	/* clearing ISC2  and applying OR operation with the mode that is   *
	 * defined in the header file.                                      */
	CLEAR_BIT(MCUCSR , ISC2);
	MCUCSR |= (INT2_MODE<<ISC2);
	/* setting the INT2 bit in the GICR register */
	SET_BIT(GICR , INT2);
}

