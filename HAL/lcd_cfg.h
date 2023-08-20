/***********************************************************
 * Name: Youssef Khaled Ahmed
 * Date: 18/8/2023
 * Description: Header file for LCD driver configurations
 ***********************************************************/

#ifndef LCD_CFG_H_
#define LCD_CFG_H_

/* including the standard types header file and the dio header file */
#include "standardTypes.h"
#include "dio.h"

/* configuring the ports where the command and data pins of the  *
 * LCD is connected.                                             */
#define LCD_CMD_PORT_ID PORTA_ID
#define LCD_DATA_PORT_ID PORTB_ID

/* configuring the pins where the data pins of the LCD is connected */
#define LCD_D4 PIN0_ID
#define LCD_D5 PIN1_ID
#define LCD_D6 PIN2_ID
#define LCD_D7 PIN4_ID

/* configuring the pins where the command pins of the LCD is connected */
#define LCD_RS PIN3_ID
#define LCD_EN PIN2_ID


/* LCD Commands */
#define LCD_CLEAR_COMMAND              0x01
#define LCD_GO_TO_HOME                 0x06
#define LCD_TWO_LINES_EIGHT_BITS_MODE  0x38
#define LCD_TWO_LINES_FOUR_BITS_MODE   0x28
#define LCD_CURSOR_OFF                 0x0C
#define LCD_CURSOR_ON                  0x0E
#define LCD_CURSOR_BLINK               0x0F
#define LCD_SET_CURSOR_LOCATION        0x80


#endif /* LCD_CFG_H_ */
