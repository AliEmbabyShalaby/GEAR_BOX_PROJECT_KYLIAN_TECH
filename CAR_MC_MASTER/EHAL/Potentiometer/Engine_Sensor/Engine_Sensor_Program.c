/***
 *           ______            _                _____                     __    _____
 *          / ____/___  ____ _(_)___  ___      / ___/____  ___  ___  ____/ /   / ___/___  ____  _________  __________
 *         / __/ / __ \/ __ `/ / __ \/ _ \     \__ \/ __ \/ _ \/ _ \/ __  /    \__ \/ _ \/ __ \/ ___/ __ \/ ___/ ___/
 *        / /___/ / / / /_/ / / / / /  __/    ___/ / /_/ /  __/  __/ /_/ /    ___/ /  __/ / / (__  ) /_/ / /  / /__
 *       /_____/_/ /_/\__, /_/_/ /_/\___/____/____/ .___/\___/\___/\__,_/____/____/\___/_/ /_/____/\____/_(_) \___/
 *                   /____/            /_____/   /_/                   /_____/
 */
#include "Engine_Sensor_Interface.h"

ERROR_STATE Speed_Analog_Initialize(){
	ERROR_STATE state_error = SUCCESS;
	if(ADC_Initialize()){
		state_error = SUCCESS;
	}else{
		state_error = FAIL;
	}
	return state_error;
}

ERROR_STATE Speed_Analog_Read(UINT16_t* POT_value){
	ERROR_STATE state_error = SUCCESS;
	if(ADC_Read(Speed_Analog_PIN,POT_value)){
		state_error = SUCCESS;
	}else{
		state_error = FAIL;
	}
	return state_error;
}

