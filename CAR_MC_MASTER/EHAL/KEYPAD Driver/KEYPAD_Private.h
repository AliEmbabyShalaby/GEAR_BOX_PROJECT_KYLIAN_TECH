/***
 *        __ __ ________  ______  ___    ____       ____       _             __         __
 *       / //_// ____/\ \/ / __ \/   |  / __ \     / __ \_____(_)   ______ _/ /____    / /_
 *      / ,<  / __/    \  / /_/ / /| | / / / /    / /_/ / ___/ / | / / __ `/ __/ _ \  / __ \
 *     / /| |/ /___    / / ____/ ___ |/ /_/ /    / ____/ /  / /| |/ / /_/ / /_/  __/ / / / /
 *    /_/ |_/_____/   /_/_/   /_/  |_/_____/____/_/   /_/  /_/ |___/\__,_/\__/\___(_)_/ /_/
 *                                        /_____/
 */

#ifndef KEYPAD_PRIVATE_H_
#define KEYPAD_PRIVATE_H_

#include "CPU_Configuration.h"
#include "DIO_Interface.h"
/************************************************************************/
/*                         Data Definitions:                            */
/************************************************************************/

#define KEYPAD_PORT_OUT DIO_PORTC
#define KEYPAD_PORT_INP DIO_PORTD

#define KEYPAD_PIN_OUT0 DIO_PIN5
#define KEYPAD_PIN_OUT1 DIO_PIN4
#define KEYPAD_PIN_OUT2 DIO_PIN3
#define KEYPAD_PIN_OUT3 DIO_PIN2

#define KEYPAD_PIN_INP0 DIO_PIN7
#define KEYPAD_PIN_INP1 DIO_PIN6
#define KEYPAD_PIN_INP2 DIO_PIN5
#define KEYPAD_PIN_INP3 DIO_PIN3

#define KEYPAD_INP  DIO_INPUT
#define KEYPAD_OUT  DIO_OUTPUT

#define KEYPAD_LOW  DIO_LOW
#define KEYPAD_HIGH DIO_HIGH

#define KEYPAD_COL_STRT 7
#define KEYPAD_COL_END  4

#define KEYPAD_ROW_STRT 2
#define KEYPAD_ROW_END  5

#define KEYPAD_PRESSED  0


#endif /* KEYPAD_PRIVATE_H_ */
