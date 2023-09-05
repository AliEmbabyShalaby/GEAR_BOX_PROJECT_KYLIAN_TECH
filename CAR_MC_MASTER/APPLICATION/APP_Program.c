/***
 *        ___    ____  ____   ____      __            ____
 *       /   |  / __ \/ __ \ /  _/___  / /____  _____/ __/___ _________   _____
 *      / /| | / /_/ / /_/ / / // __ \/ __/ _ \/ ___/ /_/ __ `/ ___/ _ \ / ___/
 *     / ___ |/ ____/ ____/_/ // / / / /_/  __/ /  / __/ /_/ / /__/  __// /__
 *    /_/  |_/_/   /_/____/___/_/ /_/\__/\___/_/  /_/  \__,_/\___/\___(_)___/
 *                  /_____/
 */
#include <APP_Interface.h>
extern bool Parking_Flag, Reverse_Flag, Normal_Flag, Drive_Flag;

Master_Config My_Master = { SPI_INTERRUPT_DISABLE,
SPI_MSB,
SPI_RISING_LEADING,
SPI_SAMPLE_LEADING,
SPI_PRESCALER_4 };

ERROR_STATE Application_Initialize() {
	ERROR_STATE state_error = SUCCESS;
	SPI_Init_Master(&My_Master);

	LCD_Initialize();
	load_custom_characters();
	KEYPAD_Initialize();
	Speed_Analog_Initialize();
	BLUE_LED_Initializ();
	GREEN_LED_Initializ();
	YELLOW_LED_Initializ();
	BUZZER_Initialize();
	LCD_LINE_position(LCD_LINE1, 0);
	LCD_Write_String("GEAR_BOX_PROJECT");
	LCD_LINE_position(LCD_LINE2, 2);
	LCD_Write_String("^_^ Welcome ^_^");
	LCD_LINE_position(LCD_LINE4, 2);
	LCD_Write_String("BY: KYLIAN TECH");

	_delay_ms(2000);
	LCD_Clear();
	LCD_LINE_position(LCD_LINE1, 0);
	LCD_Write_String("Ali Embaby - 980");
	LCD_LINE_position(LCD_LINE2, 0);
	LCD_Write_String("Seif Shebl - 894");
	LCD_LINE_position(LCD_LINE3, 0);
	LCD_Write_String("Ahmed Nasr - 1069");
	LCD_LINE_position(LCD_LINE4, 0);
	LCD_Write_String("Azza Saeed - 912");
	_delay_ms(2000);
	LCD_Clear();

	return state_error;
}
/*Super Loop Checks the flag of which state*/
ERROR_STATE MAIN_Application() {
	ERROR_STATE state_error = SUCCESS;
	if (Parking_Flag) {
		Parking_State();
	} else {
		if (Normal_Flag) {
			Normal_State();
		} else {
			if (Reverse_Flag) {
				Reverse_State();
			} else {
				if (Drive_Flag) {
					Drive_State();
				}
			}
		}
	}
	return state_error;
}

