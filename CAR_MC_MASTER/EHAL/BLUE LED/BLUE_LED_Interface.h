/***
 *        ____  __    __  ________     __    __________       ____      __            ____                  __
 *       / __ )/ /   / / / / ____/    / /   / ____/ __ \     /  _/___  / /____  _____/ __/___ _________    / /_
 *      / __  / /   / / / / __/      / /   / __/ / / / /     / // __ \/ __/ _ \/ ___/ /_/ __ `/ ___/ _ \  / __ \
 *     / /_/ / /___/ /_/ / /___     / /___/ /___/ /_/ /    _/ // / / / /_/  __/ /  / __/ /_/ / /__/  __/ / / / /
 *    /_____/_____/\____/_____/____/_____/_____/_____/____/___/_/ /_/\__/\___/_/  /_/  \__,_/\___/\___(_)_/ /_/
 *                           /_____/                /_____/
 */

#ifndef BLUE_LED_INTERFACE_H_
#define BLUE_LED_INTERFACE_H_

#include "BLUE_LED_Private.h"

/************************************************************************/
/*                      Functions Prototypes                            */
/************************************************************************/

ERROR_STATE BLUE_LED_Initializ(void);
ERROR_STATE BLUE_LED_ON(void);
ERROR_STATE BLUE_LED_OFF(void);
ERROR_STATE BLUE_LED_TGL(void);

#endif /* BLUE_LED_INTERFACE_H_ */
