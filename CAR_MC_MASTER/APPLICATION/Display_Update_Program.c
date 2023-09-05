/***
 *        ____  _            __                __  __          __      __            ____
 *       / __ \(_)________  / /___ ___  __    / / / /___  ____/ /___ _/ /____       / __ \_________  ____ __________ _____ ___   _____
 *      / / / / / ___/ __ \/ / __ `/ / / /   / / / / __ \/ __  / __ `/ __/ _ \     / /_/ / ___/ __ \/ __ `/ ___/ __ `/ __ `__ \ / ___/
 *     / /_/ / (__  ) /_/ / / /_/ / /_/ /   / /_/ / /_/ / /_/ / /_/ / /_/  __/    / ____/ /  / /_/ / /_/ / /  / /_/ / / / / / // /__
 *    /_____/_/____/ .___/_/\__,_/\__, /____\____/ .___/\__,_/\__,_/\__/\___/____/_/   /_/   \____/\__, /_/   \__,_/_/ /_/ /_(_)___/
 *                /_/            /____/_____/   /_/                        /_____/                /____/
 */

#include "Display_Update_Interface.h"

extern SINT16_t Current_Speed;
extern bool Limit_Flag;
extern UINT8_t Mode_Selected;
bool one_time_flag = TRUE;
UINT8_t SPEED_LIMIT = 0;

/*This the LCD HomePage
 * inputs:Status Mode
 * outputs:none*/
void Main_LCD_Display(MODES Mode) {
	/*To remove negative sign while display the value.*/
	UINT16_t Current_Speed_Positive = 0;
	if (Current_Speed < 0) {
		Current_Speed_Positive = Current_Speed * (-1);
	} else {
		Current_Speed_Positive = Current_Speed;
	}
	LCD_Curser_OFF();
	LCD_LINE_position(0, 0);
	LCD_Write_String("SPEED:");
	LCD_LINE_position(0, 6);
	LCD_Write_String("   ");
	LCD_LINE_position(0, 6);
	LCD_Write_Number(Current_Speed_Positive);
	if (Limit_Flag) {
		LCD_LINE_position(0, 10);
		LCD_Write_String("!LIM");
		LCD_LINE_position(1, 11);
		LCD_Write_Number(SPEED_LIMIT);
	}
	LCD_LINE_position(2, 0);
	LCD_Write_String("1)TGL MAXSPEED");
	LCD_LINE_position(3, 0);
	LCD_Write_String("2)SET MAXSPEED");

	switch (Mode) {
	case Parking_Mode:
		BLUE_LED_OFF();
		GREEN_LED_OFF();
		YELLOW_LED_ON();
		BUZZER_OFF();
		Display_Letter(P);
		break;
	case Reverse_Mode:
		BLUE_LED_OFF();
		GREEN_LED_OFF();
		YELLOW_LED_OFF();
		BUZZER_TGL();
		_delay_ms(25);
		Display_Letter(R);
		break;
	case Normal_Mode:
		BLUE_LED_ON();
		GREEN_LED_OFF();
		YELLOW_LED_OFF();
		BUZZER_OFF();
		LCD_LINE_position(2, 19);
		Display_Letter(N);
		break;
	case Drive_Mode:
		BLUE_LED_OFF();
		GREEN_LED_ON();
		YELLOW_LED_OFF();
		BUZZER_OFF();
		LCD_LINE_position(3, 19);
		Display_Letter(D);
		break;
	default:
		break;
	}
}
/*This function Calculates Current speed value from potentiometer VR1
 * and average 30 readings
 * inputs:pointer to address that stored current speed to it.
 * outputs:none
 * */
void Current_Speed_value(SINT16_t *Speed) {
	UINT16_t speed_adj = 0;
	SINT16_t speed_val = 0;

	for (int i = 0; i < 30; i++) {
		Speed_Analog_Read(&speed_adj);
		speed_val += ((speed_adj / 2) - 262);
	}
	speed_val /= 30;
	/*Limit negative speed to -30*/
	if (speed_val < (-30)) {
		speed_val = -30;
	}
	if (Limit_Flag) {
		/*SPI read UPDATE*/
		/*One time flag to ensure reading from eeprom when needed*/
		if (one_time_flag) {
			Master_Send(UPDATE_YOURSELF);
			_delay_ms(200);
			SPEED_LIMIT = Master_Receive();
			one_time_flag = FALSE;
		}

		if (speed_val > SPEED_LIMIT) {
			speed_val = (SPEED_LIMIT);
		}
		if ((speed_val) < (SPEED_LIMIT) * (-1)) {
			speed_val = (SPEED_LIMIT) * (-1);
		}
	} else {
		one_time_flag = TRUE;
	}
	*Speed = speed_val;
}
/*This function Toggles Speed Limit
 * inputs:none
 * outputs:none
 * */
void TGL_Limit_Speed() {
	if (Current_Speed == 0) {
		LCD_Clear();
		LCD_LINE_position(0, 1);
		if (Limit_Flag) {
			LCD_Write_String("LIMIT SPEED OFF");
		} else {
			LCD_Write_String("LIMIT SPEED ON");
		}
		Limit_Flag ^= TRUE;
		Current_Speed_value(&Current_Speed);
		_delay_ms(1250);
	}
}
/*This function Setting Speed Limit Value by taking average of 20 VR2 readings and store it
 * inputs:none
 * outputs:none
 * */
void SET_LIMIT_SPEED() {
	LCD_Clear();
	LCD_LINE_position(0, 1);
	LCD_Write_String("PLEASE ADJUST VR2");
	LCD_LINE_position(1, 4);
	LCD_Write_String("TO SET VALUE");
	LCD_LINE_position(2, 3);
	LCD_Write_String("LIMIT SPEED:");
	UINT16_t CURRENT_LIMIT_VALUE = 0, limit_avrg = 0;
	KEYPAD_Read(&Mode_Selected);
	while ((Mode_Selected != 'B')) {
		/*BACK BUTTON ONLY CAN EXIT THSI LOOP TO STORE THE VALUE*/
		KEYPAD_Read(&Mode_Selected);
		LCD_LINE_position(3, 8);
		LCD_Write_String("     ");
		LCD_LINE_position(3, 8);
		limit_avrg = 0;
		for (int i = 0; i < 20; i++) {
			LIMIT_Speed_Analog_Read(&CURRENT_LIMIT_VALUE);
			limit_avrg += CURRENT_LIMIT_VALUE;
		}
		/*This calculation to limit Speed value from 1023 to 250*/
		limit_avrg = (((limit_avrg / 20) - 24) / 4);
		LCD_Write_Number(limit_avrg);

		LCD_LINE_position(3, 13);
		LCD_Write_Character(0x7F);
		_delay_ms(100);
	}
	/*SPI WRITE to Store to eeprom*/
	UINT8_t Limit_Speed_Value = 0;
	Limit_Speed_Value = (UINT8_t) limit_avrg;
	Master_Send(Limit_Speed_Value);
	_delay_ms(200);


}
/*This function Display LETTERS IN ART
 * inputs:none
 * outputs:none
 * */
void Display_Letter(Letters letter) {
	switch (letter) {
	case P:
		LCD_LINE_position(0, 14);
		LCD_Write_String(" ");
		LCD_Write_Character(3);
		LCD_Write_Character(3);
		LCD_Write_Character(3);
		LCD_LINE_position(1, 14);
		LCD_Write_Character(1);
		LCD_Write_String(" ");
		LCD_Write_Character(3);
		LCD_Write_String(" ");
		LCD_Write_Character(0);
		LCD_LINE_position(2, 14);
		LCD_Write_Character(1);
		LCD_Write_String(" ");
		LCD_Write_Character(3);
		LCD_Write_Character(3);
		LCD_Write_Character(4);
		LCD_LINE_position(3, 14);
		LCD_Write_Character(1);
		LCD_Write_Character(3);
		LCD_Write_Character(2);
		break;
	case R:
		LCD_LINE_position(0, 14);
		LCD_Write_String(" ");
		LCD_Write_Character(3);
		LCD_Write_Character(3);
		LCD_Write_Character(3);
		LCD_LINE_position(1, 14);
		LCD_Write_Character(1);
		LCD_Write_String(" ");
		LCD_Write_Character(3);
		LCD_Write_String(" ");
		LCD_Write_Character(0);
		LCD_LINE_position(2, 14);
		LCD_Write_Character(1);
		LCD_Write_String("   ");
		LCD_Write_Character(4);
		LCD_LINE_position(3, 14);
		LCD_Write_Character(1);
		LCD_Write_Character(3);
		LCD_Write_Character(5);
		LCD_Write_Character(3);
		LCD_Write_Character(6);
		break;
	case N:
		LCD_LINE_position(0, 14);
		LCD_Write_String(" ");
		LCD_Write_Character(3);
		LCD_Write_String("  ");
		LCD_Write_Character(3);
		LCD_LINE_position(1, 14);
		LCD_Write_Character(1);
		LCD_Write_String(" ");
		LCD_Write_Character(0);
		LCD_Write_String("| ");
		LCD_Write_Character(2);
		LCD_LINE_position(2, 14);
		LCD_Write_Character(1);
		LCD_Write_String(" .' ");
		LCD_Write_Character(2);
		LCD_LINE_position(3, 14);
		LCD_Write_Character(1);
		LCD_Write_Character(3);
		LCD_Write_String("|");
		LCD_Write_Character(0);
		LCD_Write_Character(3);
		LCD_Write_Character(2);
		break;
	case D:
		LCD_LINE_position(0, 14);
		LCD_Write_String(" ");
		LCD_Write_Character(3);
		LCD_Write_Character(3);
		LCD_Write_Character(3);
		LCD_LINE_position(1, 14);
		LCD_Write_Character(1);
		LCD_Write_String("   ");
		LCD_Write_Character(0);
		LCD_LINE_position(2, 14);
		LCD_Write_Character(1);
		LCD_Write_String(" |)");
		LCD_Write_Character(1);
		LCD_LINE_position(3, 14);
		LCD_Write_Character(1);
		LCD_Write_Character(3);
		LCD_Write_Character(3);
		LCD_Write_Character(3);
		LCD_Write_Character(4);
		break;
	default:
		break;
	}
}

