/***
 *        ______            _                 __    _           _ __      _____                              ____
 *       / ____/___  ____ _(_)___  ___       / /   (_)___ ___  (_) /_    / ___/___  ____  _________  _____  / __ \_________  ____ __________ _____ ___   _____
 *      / __/ / __ \/ __ `/ / __ \/ _ \     / /   / / __ `__ \/ / __/    \__ \/ _ \/ __ \/ ___/ __ \/ ___/ / /_/ / ___/ __ \/ __ `/ ___/ __ `/ __ `__ \ / ___/
 *     / /___/ / / / /_/ / / / / /  __/    / /___/ / / / / / / / /_     ___/ /  __/ / / (__  ) /_/ / /    / ____/ /  / /_/ / /_/ / /  / /_/ / / / / / // /__
 *    /_____/_/ /_/\__, /_/_/ /_/\___/____/_____/_/_/ /_/ /_/_/\__/____/____/\___/_/ /_/____/\____/_/____/_/   /_/   \____/\__, /_/   \__,_/_/ /_/ /_(_)___/
 *                /____/            /_____/                      /_____/                           /_____/                /____/
 */

#include "Engine_Limit_Sensor_Private.h"

ERROR_STATE LIMIT_Speed_Analog_Initialize(){
	ERROR_STATE state_error = SUCCESS;
	if(ADC_Initialize()){
		state_error = SUCCESS;
	}else{
		state_error = FAIL;
	}
	return state_error;
}

ERROR_STATE LIMIT_Speed_Analog_Read(UINT16_t* POT_value){
	ERROR_STATE state_error = SUCCESS;
	if(ADC_Read(LIMIT_Speed_Analog_PIN,POT_value)){
		state_error = SUCCESS;
	}else{
		state_error = FAIL;
	}
	return state_error;
}
