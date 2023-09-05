/***
 *        ____  _            __                __  __          __      __            ____      __            ____                  __
 *       / __ \(_)________  / /___ ___  __    / / / /___  ____/ /___ _/ /____       /  _/___  / /____  _____/ __/___ _________    / /_
 *      / / / / / ___/ __ \/ / __ `/ / / /   / / / / __ \/ __  / __ `/ __/ _ \      / // __ \/ __/ _ \/ ___/ /_/ __ `/ ___/ _ \  / __ \
 *     / /_/ / (__  ) /_/ / / /_/ / /_/ /   / /_/ / /_/ / /_/ / /_/ / /_/  __/    _/ // / / / /_/  __/ /  / __/ /_/ / /__/  __/ / / / /
 *    /_____/_/____/ .___/_/\__,_/\__, /____\____/ .___/\__,_/\__,_/\__/\___/____/___/_/ /_/\__/\___/_/  /_/  \__,_/\___/\___(_)_/ /_/
 *                /_/            /____/_____/   /_/                        /_____/
 */

#ifndef DISPLAY_UPDATE_INTERFACE_H_
#define DISPLAY_UPDATE_INTERFACE_H_

#include "CPU_Configuration.h"
#include "SPI_Interface.h"

#include "KEYPAD_Private.h"
#include "LCD_Private.h"
#include "Engine_Limit_Sensor_Private.h"
#include "Engine_Sensor_Private.h"

#include "GREEN_LED_Private.h"
#include "BLUE_LED_Private.h"
#include "YELLOW_LED_Private.h"
#include "Buzzer_Private.h"

typedef enum{
	Parking_Mode,
	Reverse_Mode,
	Normal_Mode,
	Drive_Mode
}MODES;
typedef enum{
	P,
	R,
	N,
	D
}Letters;

void Current_Speed_value(SINT16_t *Speed);
void Main_LCD_Display(MODES Mode) ;
void TGL_Limit_Speed();
void SET_LIMIT_SPEED();
void Display_Letter(Letters letter);

#endif /* DISPLAY_UPDATE_INTERFACE_H_ */
