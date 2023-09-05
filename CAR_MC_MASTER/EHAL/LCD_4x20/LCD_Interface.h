/***
 *        __    __________       ____      __            ____                  __
 *       / /   / ____/ __ \     /  _/___  / /____  _____/ __/___ _________    / /_
 *      / /   / /   / / / /     / // __ \/ __/ _ \/ ___/ /_/ __ `/ ___/ _ \  / __ \
 *     / /___/ /___/ /_/ /    _/ // / / / /_/  __/ /  / __/ /_/ / /__/  __/ / / / /
 *    /_____/\____/_____/____/___/_/ /_/\__/\___/_/  /_/  \__,_/\___/\___(_)_/ /_/
 *                     /_____/
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#include "LCD_Private.h"

/************************************************************************/
/*                      Functions Prototypes                            */
/************************************************************************/

ERROR_STATE LCD_Initialize(void);
ERROR_STATE LCD_Curser_OFF(void);
ERROR_STATE LCD_Curser_ON(void);
ERROR_STATE LCD_Clear(void);
ERROR_STATE LCD_Write_Command(UINT8_t command);
ERROR_STATE LCD_Write_Character(UINT8_t character);
ERROR_STATE LCD_Write_String(const char *str);
ERROR_STATE LCD_Write_Number(SINT64_t number);
ERROR_STATE LCD_Write_FloatNumber(fint64_t Fnumber);
ERROR_STATE LCD_Write_SpecialCharacter(UINT8_t Scharcter);
ERROR_STATE LCD_LINE_position(LCD_LINES row , SINT8_t column);

void load_custom_characters(void);


#endif /* LCD_INTERFACE_H_ */
