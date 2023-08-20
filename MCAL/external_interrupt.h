/******************************************************
 * Name: Youssef Khaled Ahmed
 * Date: 19/8/2023
 * Description: header file for external interrupt
 ******************************************************/

#ifndef EXTERNAL_INTERRUPT_H_
#define EXTERNAL_INTERRUPT_H_

/*including common macros as SET_BIT and other macros *
 * also including the standard types header file      */
#include "common_macros.h"
#include "standardTypes.h"


#define GLOBAL_INTERRUPT_BIT_NUM 7 /* Global interrupt bit number */

#define GLOBAL_INTERRUPT_ENABLE 1 /* enabling the global interrupt */
#define GLOBAL_INTERRUPT_DISABLE 0 /* disabling the global interrupt */

#define EXTERNAL_INT0 6 /* external interrupt 0 bit number in the GICR register */
#define EXTERNAL_INT1 7 /* external interrupt 1 bit number in the GICR register */
#define EXTERNAL_INT2 5 /* external interrupt 2 bit number in the GICR register */

#define INT0_LOW_LEVEL 0           /* low level mode for INT0 */
#define INT0_ANY_LOGICAL_CHANGE 1  /* any logical change mode for INT0 */
#define INT0_FALLING_EDGE 2        /* falling edge mode for INT0 */
#define INT0_RISING_EDGE 3         /* rising edge mode for INT0 */

#define INT1_LOW_LEVEL 0           /* low level mode for INT1 */
#define INT1_ANY_LOGICAL_CHANGE 1  /* any logical change mode for INT1 */
#define INT1_FALLING_EDGE 2        /* falling edge mode for INT1 */
#define INT1_RISING_EDGE 3         /* rising edge mode for INT1 */

#define INT2_FALLING_EDGE 0        /* falling edge mode for INT2 */
#define INT2_RISING_EDGE 1         /* rising edge mode for INT2 */

/* configuration: */
#define INT0_MODE INT0_LOW_LEVEL   /* configuring INT0 to work at low level mode*/
#define INT1_MODE INT1_FALLING_EDGE /* configuring INT1 to work at falling edge mode*/
#define INT2_MODE INT2_FALLING_EDGE /* configuring INT2 to work at falling edge mode */

/*configurations of the pin where the INT1 is connected to */
#define INT1_PORT PORTD_ID    /* the pin is at PORTD */
#define INT1_PIN PIN3_ID      /* pin number is 7 */

/* functions prototype: */
void EXTI_init(void); /* initializing the global interrupt */
void EXTI_int0_init(void); /* initializing the EXTI0 */
void EXTI_int1_init(void); /* initializing the EXTI1 */
void EXTI_int2_init(void); /* initializing the EXTI2 */


#endif /* EXTERNAL_INTERRUPT_H_ */
