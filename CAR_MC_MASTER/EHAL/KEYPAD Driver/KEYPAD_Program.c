/***
 *        __ __ ________  ______  ___    ____       ____      __            ____
 *       / //_// ____/\ \/ / __ \/   |  / __ \     /  _/___  / /____  _____/ __/___ _________   _____
 *      / ,<  / __/    \  / /_/ / /| | / / / /     / // __ \/ __/ _ \/ ___/ /_/ __ `/ ___/ _ \ / ___/
 *     / /| |/ /___    / / ____/ ___ |/ /_/ /    _/ // / / / /_/  __/ /  / __/ /_/ / /__/  __// /__
 *    /_/ |_/_____/   /_/_/   /_/  |_/_____/____/___/_/ /_/\__/\___/_/  /_/  \__,_/\___/\___(_)___/
 *                                        /_____/
 */

#include "KEYPAD_Interface.h"

const UINT8_t keypad[4][4] =
{
	{'O', 'S','B', 'P'},

	{'E', 'E', 'E','R'},

	{'E', 'E', 'E', 'N'},

	{'E', 'E', 'E', 'D'}
};

void KEYPAD_Initialize(void)
{
	DIO_SetPin_Direction(KEYPAD_PORT_OUT, KEYPAD_PIN_OUT0, KEYPAD_OUT);
	DIO_SetPin_Direction(KEYPAD_PORT_OUT, KEYPAD_PIN_OUT1, KEYPAD_OUT);
	DIO_SetPin_Direction(KEYPAD_PORT_OUT, KEYPAD_PIN_OUT2, KEYPAD_OUT);
	DIO_SetPin_Direction(KEYPAD_PORT_OUT, KEYPAD_PIN_OUT3, KEYPAD_OUT);

	DIO_SetPin_Value(KEYPAD_PORT_OUT, KEYPAD_PIN_OUT0, KEYPAD_HIGH);
	DIO_SetPin_Value(KEYPAD_PORT_OUT, KEYPAD_PIN_OUT1, KEYPAD_HIGH);
	DIO_SetPin_Value(KEYPAD_PORT_OUT, KEYPAD_PIN_OUT2, KEYPAD_HIGH);
	DIO_SetPin_Value(KEYPAD_PORT_OUT, KEYPAD_PIN_OUT3, KEYPAD_HIGH);

	DIO_SetPin_Direction(KEYPAD_PORT_INP, KEYPAD_PIN_INP0, KEYPAD_INP);
	DIO_SetPin_Direction(KEYPAD_PORT_INP, KEYPAD_PIN_INP1, KEYPAD_INP);
	DIO_SetPin_Direction(KEYPAD_PORT_INP, KEYPAD_PIN_INP2, KEYPAD_INP);
	DIO_SetPin_Direction(KEYPAD_PORT_INP, KEYPAD_PIN_INP3, KEYPAD_INP);

/*  DIO_SetPin_PULLUP(KEYPAD_PORT_OUT, KEYPAD_PIN_OUT0);
	DIO_SetPin_PULLUP(KEYPAD_PORT_OUT, KEYPAD_PIN_OUT0);
	DIO_SetPin_PULLUP(KEYPAD_PORT_OUT, KEYPAD_PIN_OUT0);
	DIO_SetPin_PULLUP(KEYPAD_PORT_OUT, KEYPAD_PIN_OUT0);*/

}

void KEYPAD_Read(UINT8_t* val)
{
	UINT8_t btn = 'E';
	UINT8_t Keypad_button=1;
	UINT8_t Row_Loc ;//i-counter
	UINT8_t Col_Loc ;//j-counter
	for (Row_Loc = KEYPAD_ROW_END; Row_Loc >= KEYPAD_ROW_STRT; Row_Loc--)
	{
			DIO_SetPin_Value(KEYPAD_PORT_OUT, Row_Loc, KEYPAD_LOW);
			for (Col_Loc = KEYPAD_COL_STRT; Col_Loc >= KEYPAD_COL_END; Col_Loc--)
			{
				if(Col_Loc == 4){
					DIO_GetPin_Value(KEYPAD_PORT_INP, 3,&Keypad_button);
						while (Keypad_button == KEYPAD_PRESSED)
						{
							DIO_GetPin_Value(KEYPAD_PORT_INP, 3,&Keypad_button);
							btn = keypad[KEYPAD_ROW_END - Row_Loc][3];
						}
						_delay_us(100);
					
				}else{
					DIO_GetPin_Value(KEYPAD_PORT_INP, Col_Loc,&Keypad_button);
						while (Keypad_button == KEYPAD_PRESSED)
						{
							DIO_GetPin_Value(KEYPAD_PORT_INP, 3,&Keypad_button);
							btn = keypad[KEYPAD_ROW_END - Row_Loc][ KEYPAD_COL_STRT - Col_Loc ];
						}
						_delay_us(100);
				}
			}
			DIO_SetPin_Value(KEYPAD_PORT_OUT, Row_Loc, KEYPAD_HIGH);
	}

	*val= btn;
}
