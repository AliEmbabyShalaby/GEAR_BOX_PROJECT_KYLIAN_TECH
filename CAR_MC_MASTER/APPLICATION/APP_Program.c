/***
 *        ___    ____  ____   ____
 *       /   |  / __ \/ __ \ / __ \_________  ____ __________ _____ ___   _____
 *      / /| | / /_/ / /_/ // /_/ / ___/ __ \/ __ `/ ___/ __ `/ __ `__ \ / ___/
 *     / ___ |/ ____/ ____// ____/ /  / /_/ / /_/ / /  / /_/ / / / / / // /__
 *    /_/  |_/_/   /_/____/_/   /_/   \____/\__, /_/   \__,_/_/ /_/ /_(_)___/
 *                  /_____/                /____/
 */

#include <APP_Interface.h>

extern bool Parking_Flag, Reverse_Flag, Normal_Flag, Drive_Flag;

bool Start_state_flag=TRUE;

Master_Config My_Master = { SPI_INTERRUPT_DISABLE,
SPI_MSB,
SPI_RISING_LEADING,
SPI_SAMPLE_LEADING,
SPI_PRESCALER_4 };
/*
 * Function: Application_Initialize
 * ------------------------------
 * Description: Initializes the application components.
 * Returns: ERROR_STATE - SUCCESS if initialization is successful, an error state otherwise.
 */
ERROR_STATE Application_Initialize() {
	ERROR_STATE state_error = SUCCESS;
	SPI_Init_Master(&My_Master);

	LCD_Initialize();
	LCD_Curser_OFF();
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


/*
 * Function: MAIN_Application
 * ------------------------------
 * Description: Super Loop that checks the flags to determine the current state.
 *              It selects and executes the appropriate state function based on the flags.
 * Returns: ERROR_STATE - SUCCESS if the super loop executes successfully, an error state otherwise.
 */
ERROR_STATE MAIN_Application() {
	ERROR_STATE state_error = SUCCESS;
	/*This condition only for the first use to assure speed = 0*/
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

