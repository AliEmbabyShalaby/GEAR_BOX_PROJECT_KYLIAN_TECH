/***
 *        ____                              ____
 *       / __ )__  __________  ___  _____  / __ \_________  ____ __________ _____ ___   _____
 *      / __  / / / /_  /_  / / _ \/ ___/ / /_/ / ___/ __ \/ __ `/ ___/ __ `/ __ `__ \ / ___/
 *     / /_/ / /_/ / / /_/ /_/  __/ /    / ____/ /  / /_/ / /_/ / /  / /_/ / / / / / // /__
 *    /_____/\__,_/ /___/___/\___/_/____/_/   /_/   \____/\__, /_/   \__,_/_/ /_/ /_(_)___/
 *                                /_____/                /____/
 */

#include "Buzzer_Interface.h"

ERROR_STATE BUZZER_Initialize(void){
	ERROR_STATE state_error = SUCCESS;
	DIO_SetPin_Direction(BUZZER_PORT,BUZZER_PIN,BUZZER_OUTPUT);
	return state_error;
}
ERROR_STATE BUZZER_ON(void){
	ERROR_STATE state_error = SUCCESS;
	DIO_SetPin_Value(BUZZER_PORT,BUZZER_PIN,BUZZER_HIGH);
	return state_error;
}
ERROR_STATE BUZZER_OFF(void){
	ERROR_STATE state_error = SUCCESS;
	DIO_SetPin_Value(BUZZER_PORT,BUZZER_PIN,BUZZER_LOW);
	return state_error;
}
ERROR_STATE BUZZER_TGL(void){
	ERROR_STATE state_error = SUCCESS;
	DIO_TglPin_Value(BUZZER_PORT,BUZZER_PIN);
	return state_error;
}
