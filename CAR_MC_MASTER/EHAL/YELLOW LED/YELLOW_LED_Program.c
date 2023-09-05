/***
 *    __  __________    __    ____ _       __     __    __________       ____      __            ____
 *    \ \/ / ____/ /   / /   / __ \ |     / /    / /   / ____/ __ \     /  _/___  / /____  _____/ __/___ _________   _____
 *     \  / __/ / /   / /   / / / / | /| / /    / /   / __/ / / / /     / // __ \/ __/ _ \/ ___/ /_/ __ `/ ___/ _ \ / ___/
 *     / / /___/ /___/ /___/ /_/ /| |/ |/ /    / /___/ /___/ /_/ /    _/ // / / / /_/  __/ /  / __/ /_/ / /__/  __// /__
 *    /_/_____/_____/_____/\____/ |__/|__/____/_____/_____/_____/____/___/_/ /_/\__/\___/_/  /_/  \__,_/\___/\___(_)___/
 *                                      /_____/                /_____/
 */
#include "YELLOW_LED_Interface.h"

void YELLOW_LED_Initializ(void){
	DIO_SetPin_Direction(YELLOW_LED_PORT,YELLOW_LED_PIN,YELLOW_LED_OUTPUT);
}
void YELLOW_LED_ON(void){
	DIO_SetPin_Value(YELLOW_LED_PORT,YELLOW_LED_PIN,YELLOW_LED_HIGH);
}
void YELLOW_LED_OFF(void){
	DIO_SetPin_Value(YELLOW_LED_PORT,YELLOW_LED_PIN,YELLOW_LED_LOW);
}
void YELLOW_LED_TGL(void){
	DIO_TglPin_Value(YELLOW_LED_PORT,YELLOW_LED_PIN);
}
