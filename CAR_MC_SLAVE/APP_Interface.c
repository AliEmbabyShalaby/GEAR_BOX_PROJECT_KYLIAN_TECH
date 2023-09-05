/***
 *        ___    ____  ____   ____      __            ____
 *       /   |  / __ \/ __ \ /  _/___  / /____  _____/ __/___ _________   _____
 *      / /| | / /_/ / /_/ / / // __ \/ __/ _ \/ ___/ /_/ __ `/ ___/ _ \ / ___/
 *     / ___ |/ ____/ ____/_/ // / / / /_/  __/ /  / __/ /_/ / /__/  __// /__
 *    /_/  |_/_/   /_/____/___/_/ /_/\__/\___/_/  /_/  \__,_/\___/\___(_)___/
 *                  /_____/
 */
#include "APP_Private.h"

Slave_Config My_Slave = { SPI_INTERRUPT_ENABLE,
SPI_MSB,
SPI_RISING_LEADING,
SPI_SAMPLE_LEADING };

ERROR_STATE ApplicationS_Initialize() {
	ERROR_STATE state_error = SUCCESS;
	Global_Interrupt_Enable();
	SPI_Init_Slave(&My_Slave);
	SPI_Set_CallBack(EEPROM_READ_WRITE);
	return state_error;
}

ERROR_STATE MAINS_Application() {
	ERROR_STATE state_error = SUCCESS;

	return state_error;
}
void EEPROM_READ_WRITE(void) {
	UINT8_t Data_Received = 0;
	SPI_Read_Data(&Data_Received);
	if (Data_Received == DUMMY_DATA) {
		/*Data Received*/
	} else if (Data_Received == UPDATE_YOURSELF) {
		SPI_Send_ASynch_Byte(EEPROM_RandomRead(0X10));
	} else {
		EEPROM_ByteWrite(0X10, Data_Received);
	}
}

