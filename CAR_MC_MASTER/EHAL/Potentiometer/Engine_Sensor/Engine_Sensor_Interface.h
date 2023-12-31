/***
 *        ______            _                _____                              ____      __            ____                  __
 *       / ____/___  ____ _(_)___  ___      / ___/___  ____  _________  _____  /  _/___  / /____  _____/ __/___ _________    / /_
 *      / __/ / __ \/ __ `/ / __ \/ _ \     \__ \/ _ \/ __ \/ ___/ __ \/ ___/  / // __ \/ __/ _ \/ ___/ /_/ __ `/ ___/ _ \  / __ \
 *     / /___/ / / / /_/ / / / / /  __/    ___/ /  __/ / / (__  ) /_/ / /    _/ // / / / /_/  __/ /  / __/ /_/ / /__/  __/ / / / /
 *    /_____/_/ /_/\__, /_/_/ /_/\___/____/____/\___/_/ /_/____/\____/_/____/___/_/ /_/\__/\___/_/  /_/  \__,_/\___/\___(_)_/ /_/
 *                /____/            /_____/                           /_____/
 */

#ifndef ENGINE_SENSOR_INTERFACE_H_
#define ENGINE_SENSOR_INTERFACE_H_

#include "Engine_Sensor_Private.h"

/************************************************************************/
/*                      Functions Prototypes                            */
/************************************************************************/

ERROR_STATE Speed_Analog_Initialize();
ERROR_STATE Speed_Analog_Read(UINT16_t* POT_value);

#endif /* ENGINE_SENSOR_INTERFACE_H_ */
