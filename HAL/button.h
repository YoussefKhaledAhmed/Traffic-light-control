/*********************************************************************
 * Name of the group: Group (c)
 * Names of the members: Youssef Khaled
 *                       Hazem Mohamed
 *                       Mark Ehab
 * Date: 20/8/2023
 * Description: header file for the button where the INT1 connected
 *********************************************************************/


#ifndef BUTTON_H_
#define BUTTON_H_

/* including the dio.h for setting the direction of the pin and external      *
 * interrupt header file to initialize the external interrupt and the global  *
 * interrupt.                                                                 */
#include "../MCAL/dio.h"
#include "../MCAL/external_interrupt.h"

void BUTTON_init(); /* initializing the button */


#endif /* BUTTON_H_ */
