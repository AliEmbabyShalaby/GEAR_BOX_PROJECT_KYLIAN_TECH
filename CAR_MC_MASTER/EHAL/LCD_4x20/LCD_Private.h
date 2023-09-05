/***
 *        __    __________       ____       _             __         __
 *       / /   / ____/ __ \     / __ \_____(_)   ______ _/ /____    / /_
 *      / /   / /   / / / /    / /_/ / ___/ / | / / __ `/ __/ _ \  / __ \
 *     / /___/ /___/ /_/ /    / ____/ /  / /| |/ / /_/ / /_/  __/ / / / /
 *    /_____/\____/_____/____/_/   /_/  /_/ |___/\__,_/\__/\___(_)_/ /_/
 *                     /_____/
 */

#ifndef LCD_PRIVATE_H_
#define LCD_PRIVATE_H_

#include "CPU_Configuration.h"
#include "DIO_Interface.h"

/************************************************************************/
/*                         Data Definitions:                            */
/************************************************************************/

#define LCD_DATA_PORT  DIO_PORTB
#define LCD_CNTRL_PORT DIO_PORTA

#define LCD_RS DIO_PIN3
#define LCD_EN DIO_PIN2


#define LCD_D4 DIO_PIN0
#define LCD_D5 DIO_PIN1
#define LCD_D6 DIO_PIN2
#define LCD_D7 DIO_PIN4

#define LCD_OUT  DIO_OUTPUT
#define LCD_LOW  DIO_LOW
#define LCD_HIGH DIO_HIGH


#define DICIMAL_POINT_ACCURACY 8

typedef enum{
	LCD_LINE1,
	LCD_LINE2,
	LCD_LINE3,
	LCD_LINE4
}LCD_LINES;



#endif /* LCD_PRIVATE_H_ */
