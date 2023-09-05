/***
 *       ______                ____                  ____
 *      / ____/__  ____ ______/ __ )____  _  __     / __ \_________  ____ __________ _____ ___   _____
 *     / / __/ _ \/ __ `/ ___/ __  / __ \| |/_/    / /_/ / ___/ __ \/ __ `/ ___/ __ `/ __ `__ \ / ___/
 *    / /_/ /  __/ /_/ / /  / /_/ / /_/ />  <     / ____/ /  / /_/ / /_/ / /  / /_/ / / / / / // /__
 *    \____/\___/\__,_/_/  /_____/\____/_/|_|____/_/   /_/   \____/\__, /_/   \__,_/_/ /_/ /_(_)___/
 *                                         /_____/                /____/
 */

#include "GearBox_Interface.h"

SINT16_t Current_Speed = 0;

UINT8_t Mode_Selected = 'E';
bool Parking_Flag = TRUE, Reverse_Flag = FALSE, Normal_Flag = FALSE,
		Drive_Flag = FALSE, Limit_Flag = FALSE;

void Parking_State() {
	LCD_Clear();
	KEYPAD_Read(&Mode_Selected);
	while ((Mode_Selected == 'E' || Mode_Selected == 'P' || Mode_Selected == 'B')) {
		Current_Speed=0;
		Main_LCD_Display(Parking_Mode);
		KEYPAD_Read(&Mode_Selected);
		Current_Speed_value(&Current_Speed);
	}
	if (Current_Speed > 0) {
		Drive_Flag = TRUE;
		Parking_Flag = FALSE;
	}
	if (Current_Speed < 0) {
		Reverse_Flag = TRUE;
		Parking_Flag = FALSE;
	}
	switch (Mode_Selected) {
	case 'R':
		if (Current_Speed == 0 || Current_Speed < 0) {
			Reverse_Flag = TRUE;
			Parking_Flag = FALSE;
		}
		break;
	case 'N':
		Normal_Flag = TRUE;
		Parking_Flag = FALSE;
		break;
	case 'D':
		if (Current_Speed == 0 || Current_Speed > 0) {
			Drive_Flag = TRUE;
			Parking_Flag = FALSE;
		}
		break;
	case 'O':
		TGL_Limit_Speed();
		break;
	case 'S':
		SET_LIMIT_SPEED();
		break;
	default:
		break;
	}
}
void Reverse_State() {
	LCD_Clear();
	KEYPAD_Read(&Mode_Selected);
	while ((Mode_Selected == 'E' || Mode_Selected == 'R' || Mode_Selected == 'B')
			&& Current_Speed <= 0) {
		Main_LCD_Display(Reverse_Mode);
		KEYPAD_Read(&Mode_Selected);
		Current_Speed_value(&Current_Speed);
	}
	if (Current_Speed > 0) {
		Drive_Flag = TRUE;
		Reverse_Flag = FALSE;
	}
	switch (Mode_Selected) {
	case 'P':
		if (Current_Speed == 0) {
			Parking_Flag = TRUE;
			Reverse_Flag = FALSE;
		}
		break;
	case 'N':
		Normal_Flag = TRUE;
		Reverse_Flag = FALSE;
		break;
	case 'D':
		if (Current_Speed == 0 || Current_Speed > 0) {
			Drive_Flag = TRUE;
			Reverse_Flag = FALSE;
		}
		break;
	case 'O':
		TGL_Limit_Speed();
		break;
	case 'S':
		SET_LIMIT_SPEED();
		break;
	default:

		break;
	}
}
void Normal_State() {
	LCD_Clear();
	KEYPAD_Read(&Mode_Selected);
	while (Mode_Selected == 'E' || Mode_Selected == 'N' || Mode_Selected == 'B') {
		Main_LCD_Display(Normal_Mode);
		KEYPAD_Read(&Mode_Selected);
	}
	switch (Mode_Selected) {
	case 'P':
		if (Current_Speed == 0) {
			Parking_Flag = TRUE;
			Normal_Flag = FALSE;
		}
		break;
	case 'R':
		if (Current_Speed == 0 || Current_Speed < 0) {
			Reverse_Flag = TRUE;
			Normal_Flag = FALSE;
		}
		break;
	case 'D':
		if (Current_Speed == 0 || Current_Speed > 0) {
			Drive_Flag = TRUE;
			Normal_Flag = FALSE;
		}
		break;
	case 'O':
		TGL_Limit_Speed();
		break;
	case 'S':
		SET_LIMIT_SPEED();
		break;
	default:
		/**/
		break;
	}
}
void Drive_State() {
	LCD_Clear();
	KEYPAD_Read(&Mode_Selected);
	while ((Mode_Selected == 'E' || Mode_Selected == 'D' || Mode_Selected == 'B')
			&& Current_Speed >= 0) {
		Main_LCD_Display(Drive_Mode);
		KEYPAD_Read(&Mode_Selected);
		Current_Speed_value(&Current_Speed);
	}
	if (Current_Speed <= 0) {
		Reverse_Flag = TRUE;
		Drive_Flag = FALSE;
	}
	switch (Mode_Selected) {
	case 'P':
		if (Current_Speed == 0) {
			Parking_Flag = TRUE;
			Drive_Flag = FALSE;
		}
		break;
	case 'R':
		if (Current_Speed == 0 || Current_Speed < 0) {
			Reverse_Flag = TRUE;
			Drive_Flag = FALSE;
		}
		break;
	case 'N':
		if (Current_Speed == 0 || Current_Speed > 0) {
			Normal_Flag = TRUE;
			Drive_Flag = FALSE;
		}
		break;
	case 'O':
		TGL_Limit_Speed();
		break;
	case 'S':
		SET_LIMIT_SPEED();
		break;
	default:
		/**/
		break;
	}
}
