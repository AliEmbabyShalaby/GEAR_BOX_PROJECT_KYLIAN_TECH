/***
 *        __    __________       ____      __            ____
 *       / /   / ____/ __ \     /  _/___  / /____  _____/ __/___ _________   _____
 *      / /   / /   / / / /     / // __ \/ __/ _ \/ ___/ /_/ __ `/ ___/ _ \ / ___/
 *     / /___/ /___/ /_/ /    _/ // / / / /_/  __/ /  / __/ /_/ / /__/  __// /__
 *    /_____/\____/_____/____/___/_/ /_/\__/\___/_/  /_/  \__,_/\___/\___(_)___/
 *                     /_____/
 */
#include "LCD_Interface.h"


ERROR_STATE LCD_Initialize(void)
{
	ERROR_STATE state_error = SUCCESS;
	//Define direction for pins
	DIO_SetPin_Direction(LCD_DATA_PORT, LCD_D4, LCD_OUT);
	DIO_SetPin_Direction(LCD_DATA_PORT, LCD_D5, LCD_OUT);
	DIO_SetPin_Direction(LCD_DATA_PORT, LCD_D6, LCD_OUT);
	DIO_SetPin_Direction(LCD_DATA_PORT, LCD_D7, LCD_OUT);

	DIO_SetPin_Direction(LCD_CNTRL_PORT, LCD_RS, LCD_OUT);
	DIO_SetPin_Direction(LCD_CNTRL_PORT, LCD_EN, LCD_OUT);
	_delay_ms(20);
	LCD_Write_Command(0x33);
	LCD_Write_Command(0x32);
	LCD_Write_Command(0x28);
	LCD_Write_Command(0x01);
	LCD_Write_Command(0x0F);
	_delay_ms(10);
	return state_error;
}

ERROR_STATE LCD_Curser_OFF(void)
{
	ERROR_STATE state_error = SUCCESS;
	LCD_Write_Command(0x0C);
	return state_error;
}

ERROR_STATE LCD_Curser_ON(void)
{
	ERROR_STATE state_error = SUCCESS;
	LCD_Write_Command(0x0F);
	return state_error;
}

ERROR_STATE LCD_Clear(void)
{
	ERROR_STATE state_error = SUCCESS;
	LCD_Write_Command(0x01);
	return state_error;
}

ERROR_STATE LCD_Write_Command(UINT8_t command)
{
	ERROR_STATE state_error = SUCCESS;
	//Send high nibble first
	//LCD = (LCD & 0x0F) | (command & 0xF0);
	DIO_SetPin_Value(LCD_DATA_PORT,LCD_D7,GET_BIT(command,7));
	DIO_SetPin_Value(LCD_DATA_PORT,LCD_D6,GET_BIT(command,6));
	DIO_SetPin_Value(LCD_DATA_PORT,LCD_D5,GET_BIT(command,5));
	DIO_SetPin_Value(LCD_DATA_PORT,LCD_D4,GET_BIT(command,4));
	//Register select will select control register
	DIO_SetPin_Value(LCD_CNTRL_PORT, LCD_RS, LCD_LOW);
	//Write on LCD
	//Send high to low pulse
	DIO_SetPin_Value(LCD_CNTRL_PORT, LCD_EN, LCD_HIGH);
	_delay_us(1);
	DIO_SetPin_Value(LCD_CNTRL_PORT, LCD_EN, LCD_LOW);
	_delay_us(200);
	//Send low nibble
	//LCD =  (LCD & 0x0F) | (command << 4);
	DIO_SetPin_Value(LCD_DATA_PORT,LCD_D7,GET_BIT(command,3));
	DIO_SetPin_Value(LCD_DATA_PORT,LCD_D6,GET_BIT(command,2));
	DIO_SetPin_Value(LCD_DATA_PORT,LCD_D5,GET_BIT(command,1));
	DIO_SetPin_Value(LCD_DATA_PORT,LCD_D4,GET_BIT(command,0));
	//Send high to low pulse
	DIO_SetPin_Value(LCD_CNTRL_PORT, LCD_EN, LCD_HIGH);
	_delay_us(1);
	DIO_SetPin_Value(LCD_CNTRL_PORT, LCD_EN, LCD_LOW);
	_delay_ms(2);
	return state_error;
}

ERROR_STATE LCD_Write_Character(UINT8_t character)
{
	ERROR_STATE state_error = SUCCESS;
	//Send high nibble first
	//LCD = (LCD & 0x0F) | (character & 0xF0);
	DIO_SetPin_Value(LCD_DATA_PORT,LCD_D7,GET_BIT(character,7));
	DIO_SetPin_Value(LCD_DATA_PORT,LCD_D6,GET_BIT(character,6));
	DIO_SetPin_Value(LCD_DATA_PORT,LCD_D5,GET_BIT(character,5));
	DIO_SetPin_Value(LCD_DATA_PORT,LCD_D4,GET_BIT(character,4));
	//Register select will select data register
	DIO_SetPin_Value(LCD_CNTRL_PORT, LCD_RS, LCD_HIGH);
	//Write on LCD

	//Send high to low pulse
	DIO_SetPin_Value(LCD_CNTRL_PORT, LCD_EN, LCD_HIGH);
	_delay_us(1);
	DIO_SetPin_Value(LCD_CNTRL_PORT, LCD_EN, LCD_LOW);
	_delay_us(200);
	//Send lower nibble
	//LCD =  (LCD & 0x0F) | (character << 4);
	DIO_SetPin_Value(LCD_DATA_PORT,LCD_D7,GET_BIT(character,3));
	DIO_SetPin_Value(LCD_DATA_PORT,LCD_D6,GET_BIT(character,2));
	DIO_SetPin_Value(LCD_DATA_PORT,LCD_D5,GET_BIT(character,1));
	DIO_SetPin_Value(LCD_DATA_PORT,LCD_D4,GET_BIT(character,0));
	//Send high to low pulse
	DIO_SetPin_Value(LCD_CNTRL_PORT, LCD_EN, LCD_HIGH);
	_delay_us(1);
	DIO_SetPin_Value(LCD_CNTRL_PORT, LCD_EN, LCD_LOW);
	_delay_ms(2);
	return state_error;
}

ERROR_STATE LCD_Write_String(const char *str)
{
	ERROR_STATE state_error = SUCCESS;
	while (*str != '\0')
	{
		LCD_Write_Character(*str);
		str++;
	}
	return state_error;
}

ERROR_STATE LCD_Write_Number(SINT64_t number)
{
	ERROR_STATE state_error = SUCCESS;
	if(number < 0){
		LCD_Write_Character('-');
		number*=(-1);
	}
	SINT64_t num = number;
	UINT16_t digit = 0;
	while(num != 0){
		digit++;
		num/=10;
	}
	if(number == 0){
		LCD_Write_Character('0');
		}else{
		UINT8_t arr_num[20];

		for(int i = digit-1 ; i >= 0 ;i--){
			arr_num[i]=number %10 + '0';
			number/=10;
		}
		//itoa(number , arr_num , 10);
		for(int i =0 ; i<digit;i++){
			LCD_Write_Character(arr_num[i]);
		}
	}
	return state_error;
}


/*
Inputs:	row and column
Output:	state
Description: Moves the cursor position to the provided
row and column.
*/
ERROR_STATE LCD_LINE_position(LCD_LINES row , SINT8_t column){
	ERROR_STATE state_error = SUCCESS;
	UINT8_t address = 0;

	if(column < 20 && column >= 0){
		switch(row){
			case LCD_LINE1:
			address = 0x00;
			break;
			case LCD_LINE2:
			address = 0x40;
			break;
			case LCD_LINE3:
			address = 0x14;
			break;
			case LCD_LINE4:
			address = 0x54;
			break;
			default:
			state_error = FAIL;
			break;
		}
		if(SUCCESS == state_error){
			address += column;
			LCD_Write_Command(0x80+address);
			}else{
			;
		}
		}else{
		state_error = FAIL;
	}

	return state_error;
}
// Define custom character patterns
// Each byte represents a row of the character (8 rows in total)
const UINT8_t P_0[8] = {
    0b10000,
    0b11000,
    0b01100,
    0b00110,
    0b00010,
    0b00011,
    0b00001,
	0b00001
};

const UINT8_t P_1[8] = {
    0b00001,
    0b00001,
	0b00001,
    0b00001,
	0b00001,
	0b00001,
	0b00001,
    0b00001
};

const UINT8_t P_2[8] = {
    0b10000,
    0b10000,
    0b10000,
    0b10000,
    0b10000,
    0b10000,
    0b10000,
    0b10000
};
const UINT8_t P_3[8] = {
	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b11111
};
const UINT8_t P_4[8] = {
    0b00001,
    0b00011,
    0b00010,
    0b00110,
    0b01100,
    0b11000,
    0b10000,
	0b00000
};
const UINT8_t P_5[8] = {
    0b00000,
    0b00100,
    0b00100,
    0b01010,
    0b10001,
    0b10001,
    0b10001,
	0b10001,
};
const UINT8_t P_6[8] = {
    0b10000,
    0b11000,
    0b01100,
    0b00110,
    0b00010,
    0b00011,
    0b00001,
	0b11111
};
// Function to load custom characters into CGRAM
void load_custom_characters() {
    LCD_Write_Command(0x40);  // Set CGRAM address to 0x40
    for (int i = 0; i < 8; i++) {
          LCD_Write_Character(P_0[i]);
    }
    LCD_Write_Command(0x48);  // Set CGRAM address to 0x48
    for (int i = 0; i < 8; i++) {
        	LCD_Write_Character(P_1[i]);
    }
    LCD_Write_Command(0x50);  // Set CGRAM address to 0x50
    for (int i = 0; i < 8; i++) {
        	LCD_Write_Character(P_2[i]);
    }
    LCD_Write_Command(0x58);  // Set CGRAM address to 0x58
    for (int i = 0; i < 8; i++) {
        	LCD_Write_Character(P_3[i]);
    }
    LCD_Write_Command(0x60);  // Set CGRAM address to 0x60
    for (int i = 0; i < 8; i++) {
        	LCD_Write_Character(P_4[i]);
    }
    LCD_Write_Command(0x68);  // Set CGRAM address to 0x68
    for (int i = 0; i < 8; i++) {
        	LCD_Write_Character(P_5[i]);
    }
    LCD_Write_Command(0x70);  // Set CGRAM address to 0x70
    for (int i = 0; i < 8; i++) {
        	LCD_Write_Character(P_6[i]);
    }
    LCD_Write_Command(0x80);  // Set cursor to the beginning of the first line
}
