/***
 *       __________  _____________   __     __    __________       ____       _             __         __
 *      / ____/ __ \/ ____/ ____/ | / /    / /   / ____/ __ \     / __ \_____(_)   ______ _/ /____    / /_
 *     / / __/ /_/ / __/ / __/ /  |/ /    / /   / __/ / / / /    / /_/ / ___/ / | / / __ `/ __/ _ \  / __ \
 *    / /_/ / _, _/ /___/ /___/ /|  /    / /___/ /___/ /_/ /    / ____/ /  / /| |/ / /_/ / /_/  __/ / / / /
 *    \____/_/ |_/_____/_____/_/ |_/____/_____/_____/_____/____/_/   /_/  /_/ |___/\__,_/\__/\___(_)_/ /_/
 *                                /_____/                /_____/
 */

#ifndef GREEN_LED_PRIVATE_H_
#define GREEN_LED_PRIVATE_H_
// Configuration:
#include "CPU_Configuration.h"
#include "DIO_Interface.h"
/************************************************************************/
/*                         Data Definitions:                            */
/************************************************************************/

#define GREEN_LED_PIN		DIO_PIN4
#define GREEN_LED_PORT		DIO_PORTA

#define GREEN_LED_OUTPUT	DIO_OUTPUT

#define GREEN_LED_HIGH		DIO_HIGH
#define GREEN_LED_LOW		DIO_LOW

/************************************************************************/
/*                      Functions Prototypes                            */
/************************************************************************/

void GREEN_LED_Initializ(void);
void GREEN_LED_ON(void);
void GREEN_LED_OFF(void);
void GREEN_LED_TGL(void);



#endif /* GREEN_LED_PRIVATE_H_ */
