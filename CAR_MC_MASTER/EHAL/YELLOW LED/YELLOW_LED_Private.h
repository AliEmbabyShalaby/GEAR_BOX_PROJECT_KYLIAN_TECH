/***
 *    __  __________    __    ____ _       __     __    __________       ____       _             __         __
 *    \ \/ / ____/ /   / /   / __ \ |     / /    / /   / ____/ __ \     / __ \_____(_)   ______ _/ /____    / /_
 *     \  / __/ / /   / /   / / / / | /| / /    / /   / __/ / / / /    / /_/ / ___/ / | / / __ `/ __/ _ \  / __ \
 *     / / /___/ /___/ /___/ /_/ /| |/ |/ /    / /___/ /___/ /_/ /    / ____/ /  / /| |/ / /_/ / /_/  __/ / / / /
 *    /_/_____/_____/_____/\____/ |__/|__/____/_____/_____/_____/____/_/   /_/  /_/ |___/\__,_/\__/\___(_)_/ /_/
 *                                      /_____/                /_____/
 */

#ifndef YELLOW_LED_PRIVATE_H_
#define YELLOW_LED_PRIVATE_H_

#include "CPU_Configuration.h"
#include "DIO_Interface.h"

/************************************************************************/
/*                         Data Definitions:                            */
/************************************************************************/

#define YELLOW_LED_PIN		DIO_PIN6
#define YELLOW_LED_PORT		DIO_PORTA

#define YELLOW_LED_OUTPUT	DIO_OUTPUT

#define YELLOW_LED_HIGH		DIO_HIGH
#define YELLOW_LED_LOW		DIO_LOW


#endif /* YELLOW_LED_PRIVATE_H_ */
