/************************************************
 * Name: Youssef Khaled Ahmed
 * Date: 18/8/2023
 * Description: Header file for LCD driver
 ************************************************/

#ifndef LCD_H_
#define LCD_H_

/* including the LCD configuration header file */
#include "lcd_cfg.h"


/* Functions prototypes: */
STATUS LCD_init(void);                 /* Initializing the LCD*/
STATUS LCD_sendCommand(uint8);         /* function to send commands */
STATUS LCD_displayCharacter(uint8);    /* function to display character */
STATUS LCD_displayString(uint8 *);     /* function to display string*/
STATUS LCD_moveCursor(uint8 , uint8);  /*function to move the cursor */
/*function to display the string in specific row and column*/
STATUS LCD_displayStringRowCol(uint8 , uint8 , const uint8 *);
/* function to convert the integer to string and display it*/
STATUS LCD_integerToString(int);
STATUS LCD_clearScreen(void);          /* function to clear the screen*/


#endif /* LCD_H_ */
