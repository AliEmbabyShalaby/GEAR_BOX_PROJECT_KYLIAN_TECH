/***
 *        ____                              ____       _             __         __
 *       / __ )__  __________  ___  _____  / __ \_____(_)   ______ _/ /____    / /_
 *      / __  / / / /_  /_  / / _ \/ ___/ / /_/ / ___/ / | / / __ `/ __/ _ \  / __ \
 *     / /_/ / /_/ / / /_/ /_/  __/ /    / ____/ /  / /| |/ / /_/ / /_/  __/ / / / /
 *    /_____/\__,_/ /___/___/\___/_/____/_/   /_/  /_/ |___/\__,_/\__/\___(_)_/ /_/
 *                                /_____/
 */

#ifndef BUZZER_PRIVATE_H_
#define BUZZER_PRIVATE_H_


#include "CPU_Configuration.h"
#include "DIO_Interface.h"

/************************************************************************/
/*                         Data Definitions:                            */
/************************************************************************/

#define BUZZER_PIN		DIO_PIN6
#define BUZZER_PORT		DIO_PORTC

#define BUZZER_OUTPUT	DIO_OUTPUT

#define BUZZER_HIGH		DIO_HIGH
#define BUZZER_LOW		DIO_LOW



#endif /* BUZZER_PRIVATE_H_ */
