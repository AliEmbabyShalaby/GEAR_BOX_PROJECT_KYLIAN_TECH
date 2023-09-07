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

MODES mode_state;

/*
 * Function: Parking_State
 * ------------------------------
 * Description: Handles the Parking state of the application.
 *              It reads the keypad for mode selection and manages state transitions.
 *              Displays information on the LCD and sets flags accordingly.
 * Returns: void
 */
void Parking_State() {
	LCD_Clear(); // Clear the LCD display
	KEYPAD_Read(&Mode_Selected); // Read the selected mode from the keypad

	// Continue processing while the selected mode is 'E', 'P', or 'B'
	while ((Mode_Selected == 'E' || Mode_Selected == 'P' || Mode_Selected == 'B')) {
		Current_Speed_value(&Current_Speed); // Read the current speed

		// If the current speed is not zero, check the speed state
		if (Current_Speed != 0) {
			Check_Speed_State();
		}

		Main_LCD_Display(Parking_Mode); // Display information on the LCD
		KEYPAD_Read(&Mode_Selected); // Read the selected mode again
	}

	// Handle state transitions based on the selected mode
	switch (Mode_Selected) {
	case 'R':
		if (Current_Speed == 0) {
			Reverse_Flag = TRUE;
			Parking_Flag = FALSE;
		}
		break;
	case 'N':
		Normal_Flag = TRUE;
		Parking_Flag = FALSE;
		mode_state = Parking_Mode;
		break;
	case 'D':
		if (Current_Speed == 0) {
			Drive_Flag = TRUE;
			Parking_Flag = FALSE;
		}
		break;
	case 'O':
		TGL_Limit_Speed(); // Toggle the speed limit
		break;
	case 'S':
		SET_LIMIT_SPEED(); // Set the speed limit
		break;
	default:
		break;
	}
}

/*
 * Function: Reverse_State
 * ------------------------------
 * Description: Handles the Reverse state of the application.
 *              Reads the keypad for mode selection and manages state transitions.
 *              Limits the current speed to 30 if it exceeds the maximum allowed speed.
 *              Displays information on the LCD and sets flags accordingly.
 * Returns: void
 */
void Reverse_State() {
	LCD_Clear(); // Clear the LCD display
	KEYPAD_Read(&Mode_Selected); // Read the selected mode from the keypad

	// Continue processing while the selected mode is 'E', 'R', 'B', 'O', or 'S'
	while ((Mode_Selected == 'E' || Mode_Selected == 'R' || Mode_Selected == 'B'
			|| Mode_Selected == 'O' || Mode_Selected == 'S')) {
		Current_Speed_value(&Current_Speed); // Read the current speed

		// Limit the current speed to 30 if it exceeds the maximum allowed speed
		if (Current_Speed > 30) {
			Current_Speed = 30;
		}

		Main_LCD_Display(Reverse_Mode); // Display information on the LCD
		KEYPAD_Read(&Mode_Selected); // Read the selected mode again
	}

	// Handle state transitions based on the selected mode
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
		mode_state = Reverse_Mode;
		break;
	case 'D':
		if (Current_Speed == 0) {
			Drive_Flag = TRUE;
			Reverse_Flag = FALSE;
		}
		break;
	default:
		break;
	}
}

/*
 * Function: Normal_State
 * ------------------------------
 * Description: Handles the Normal state of the application.
 *              Reads the keypad for mode selection and manages state transitions.
 *              Displays information on the LCD and sets flags accordingly.
 *              Also checks the current speed and enforces certain state transitions.
 *              Allows transitioning to Parking or Reverse when speed is zero,
 *              but only allows transitioning back to Normal when in Reverse or Drive.
 * Returns: void
 */
void Normal_State() {
	LCD_Clear(); // Clear the LCD display
	KEYPAD_Read(&Mode_Selected); // Read the selected mode from the keypad

	// Continue processing while the selected mode is 'E', 'N', 'B', 'O', or 'S'
	while (Mode_Selected == 'E' || Mode_Selected == 'N' || Mode_Selected == 'B'
			|| Mode_Selected == 'O' || Mode_Selected == 'S') {
		Main_LCD_Display(Normal_Mode); // Display information on the LCD
		KEYPAD_Read(&Mode_Selected); // Read the selected mode again
	}

	SINT16_t CURRENT_SPEED = 0; // Initialize the variable to store current speed
	Current_Speed_value(&CURRENT_SPEED); // Read the current speed

	// Handle state transitions based on the selected mode and current conditions
	switch (Mode_Selected) {
	case 'P':
		if (CURRENT_SPEED == 0) {
			Parking_Flag = TRUE;
			Normal_Flag = FALSE;
		}
		break;
	case 'R':
		if ((mode_state == Reverse_Mode || mode_state == Parking_Mode)
				&& CURRENT_SPEED == 0) {
			Reverse_Flag = TRUE;
			Normal_Flag = FALSE;
		}
		break;
	case 'D':
		if ((mode_state == Drive_Mode || mode_state == Parking_Mode)
				&& CURRENT_SPEED == 0) {
			Drive_Flag = TRUE;
			Normal_Flag = FALSE;
		}
		break;
	default:
		/**/
		break;
	}
}

/*
 * Function: Drive_State
 * ------------------------------
 * Description: Handles the Drive state of the application.
 *              Reads the keypad for mode selection and manages state transitions.
 *              Displays information on the LCD and sets flags accordingly.
 *              Also checks the current speed and enforces certain state transitions.
 * Returns: void
 */
void Drive_State() {
	LCD_Clear();
	KEYPAD_Read(&Mode_Selected); // Read the selected mode from the keypad

	// Continue processing while the selected mode is 'E', 'D', 'B', 'O', or 'S'
	while (Mode_Selected == 'E' || Mode_Selected == 'D' || Mode_Selected == 'B'
			|| Mode_Selected == 'O' || Mode_Selected == 'S') {
		Main_LCD_Display(Drive_Mode); // Display information on the LCD
		KEYPAD_Read(&Mode_Selected); // Read the selected mode again
		Current_Speed_value(&Current_Speed); // Read the current speed
	}

	// Handle state transitions based on the selected mode and current conditions
	switch (Mode_Selected) {
	case 'P':
		if (Current_Speed == 0) {
			Parking_Flag = TRUE;
			Drive_Flag = FALSE;
		}
		break;
	case 'R':
		if (Current_Speed == 0) {
			Reverse_Flag = TRUE;
			Drive_Flag = FALSE;
		}
		break;
	case 'N':
		Normal_Flag = TRUE;
		Drive_Flag = FALSE;
		mode_state = Drive_Mode;
		break;
	default:
		/**/
		break;
	}
}

