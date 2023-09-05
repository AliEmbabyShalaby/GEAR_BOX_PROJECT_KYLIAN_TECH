/***
 *        ________________  ____  ____  __  ___     ____
 *       / ____/ ____/ __ \/ __ \/ __ \/  |/  /    / __ \_________  ____ __________ _____ ___   _____
 *      / __/ / __/ / /_/ / /_/ / / / / /|_/ /    / /_/ / ___/ __ \/ __ `/ ___/ __ `/ __ `__ \ / ___/
 *     / /___/ /___/ ____/ _, _/ /_/ / /  / /    / ____/ /  / /_/ / /_/ / /  / /_/ / / / / / // /__
 *    /_____/_____/_/   /_/ |_|\____/_/  /_/____/_/   /_/   \____/\__, /_/   \__,_/_/ /_/ /_(_)___/
 *                                        /_____/                /____/
 */

#include "I2C_Interface.h"

#include "EEPROM_Config.h"
#include "EEPROM_Interface.h"
#include "EEPROM_Private.h"

void EEPROM_Init(){
	I2C_SetClock(EEPROM_CLK);
	I2C_Init();
}

void EEPROM_ByteWrite(UINT8_t addr, UINT8_t data){
	/*Start I2C communication*/
	I2C_MasterStart();
	/*Address the EEPROM with a write request*/
	I2C_SetSlaveAddressWithWrite(EEPROM_ADDR);
	/*Load the location in the EEPROM where the data will be stored*/
	I2C_MasterWriteData(addr);
	/*Store the user data*/
	I2C_MasterWriteData(data);
	/*Terminate the I2C communication*/
	I2C_MasterStop();
	/*Wait for EEPROM to finish the operation*/
	_delay_ms(EEPROM_R_W_TIME_IN_MS);
}

UINT8_t EEPROM_RandomRead(UINT8_t addr){
	UINT8_t data = 0;
	/*Start I2C communication for providing data address*/
	I2C_MasterStart();
	/*Address the EEPROM with a write request*/
	I2C_SetSlaveAddressWithWrite(EEPROM_ADDR);
	/*Load the location in the EEPROM where the stored data is*/
	I2C_MasterWriteData(addr);
	/*Start I2C communication for reading the data*/
	I2C_MasterRepeatStart();
	/*Address the EEPROM with a read request*/
	I2C_SetSlaveAddressWithRead(EEPROM_ADDR);
	/*Read the user data*/
	I2C_MasterReadData(&data);
	/*Terminate the I2C communication*/
	I2C_MasterStop();
	/*Wait for EEPROM to finish the operation*/
	_delay_ms(EEPROM_R_W_TIME_IN_MS);
	return data;
}
