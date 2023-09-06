/***
 *        ____  __    __  ________     __    __________       ____       _             __         __
 *       / __ )/ /   / / / / ____/    / /   / ____/ __ \     / __ \_____(_)   ______ _/ /____    / /_
 *      / __  / /   / / / / __/      / /   / __/ / / / /    / /_/ / ___/ / | / / __ `/ __/ _ \  / __ \
 *     / /_/ / /___/ /_/ / /___     / /___/ /___/ /_/ /    / ____/ /  / /| |/ / /_/ / /_/  __/ / / / /
 *    /_____/_____/\____/_____/____/_____/_____/_____/____/_/   /_/  /_/ |___/\__,_/\__/\___(_)_/ /_/
 *                           /_____/                /_____/
 */

// Configuration:
#include "CPU_Configuration.h"
#include "DIO_Interface.h"

#ifndef BLUE_LED_PRIVATE_H_
#define BLUE_LED_PRIVATE_H_

#define BLUE_LED_PIN		DIO_PIN5
#define BLUE_LED_PORT		DIO_PORTA

#define BLUE_LED_OUTPUT		DIO_OUTPUT

#define BLUE_LED_HIGH		DIO_HIGH
#define BLUE_LED_LOW		DIO_LOW

/************************************************************************/
/*                      Functions Prototypes                            */
/************************************************************************/

ERROR_STATE BLUE_LED_Initializ(void);
ERROR_STATE BLUE_LED_ON(void);
ERROR_STATE BLUE_LED_OFF(void);
ERROR_STATE BLUE_LED_TGL(void);

#endif /* BLUE_LED_PRIVATE_H_ */
