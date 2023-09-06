/***
 *       __________  _____________   __     __    __________       ____      __            ____
 *      / ____/ __ \/ ____/ ____/ | / /    / /   / ____/ __ \     /  _/___  / /____  _____/ __/___ _________   _____
 *     / / __/ /_/ / __/ / __/ /  |/ /    / /   / __/ / / / /     / // __ \/ __/ _ \/ ___/ /_/ __ `/ ___/ _ \ / ___/
 *    / /_/ / _, _/ /___/ /___/ /|  /    / /___/ /___/ /_/ /    _/ // / / / /_/  __/ /  / __/ /_/ / /__/  __// /__
 *    \____/_/ |_/_____/_____/_/ |_/____/_____/_____/_____/____/___/_/ /_/\__/\___/_/  /_/  \__,_/\___/\___(_)___/
 *                                /_____/                /_____/
 */

#include "GREEN_LED_Private.h"

void GREEN_LED_Initializ(void){
	DIO_SetPin_Direction(GREEN_LED_PORT,GREEN_LED_PIN,GREEN_LED_OUTPUT);
}
void GREEN_LED_ON(void){
	DIO_SetPin_Value(GREEN_LED_PORT,GREEN_LED_PIN,GREEN_LED_HIGH);
}
void GREEN_LED_OFF(void){
	DIO_SetPin_Value(GREEN_LED_PORT,GREEN_LED_PIN,GREEN_LED_LOW);
}
void GREEN_LED_TGL(void){
	DIO_TglPin_Value(GREEN_LED_PORT,GREEN_LED_PIN);
}
