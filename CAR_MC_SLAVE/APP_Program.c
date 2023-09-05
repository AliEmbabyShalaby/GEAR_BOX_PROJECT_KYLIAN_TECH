/***
 *        ___    ____  ____   ____
 *       /   |  / __ \/ __ \ / __ \_________  ____ __________ _____ ___   _____
 *      / /| | / /_/ / /_/ // /_/ / ___/ __ \/ __ `/ ___/ __ `/ __ `__ \ / ___/
 *     / ___ |/ ____/ ____// ____/ /  / /_/ / /_/ / /  / /_/ / / / / / // /__
 *    /_/  |_/_/   /_/____/_/   /_/   \____/\__, /_/   \__,_/_/ /_/ /_(_)___/
 *                  /_____/                /____/
 */

#include <APP_Interface.h>

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
	/*nothing just dont end the running code*/
	return state_error;
}

void EEPROM_READ_WRITE(void) {
	UINT8_t Data_Received = 0;
	SPI_Read_Data(&Data_Received);
	if (Data_Received == DUMMY_DATA) {
		/*Data Received*/
	} else if (Data_Received == UPDATE_YOURSELF) {
		/*Spi Send this value to tell eeprom to update the reading*/
		SPI_Send_ASynch_Byte(EEPROM_RandomRead(0X10));
	} else {
		/*here data is received */
		EEPROM_ByteWrite(0X10, Data_Received);
	}
}

