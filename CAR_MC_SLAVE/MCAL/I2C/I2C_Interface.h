/***
 *        _______   ______     ____      __            ____                  __
 *       /  _/__ \ / ____/    /  _/___  / /____  _____/ __/___ _________    / /_
 *       / / __/ // /         / // __ \/ __/ _ \/ ___/ /_/ __ `/ ___/ _ \  / __ \
 *     _/ / / __// /___     _/ // / / / /_/  __/ /  / __/ /_/ / /__/  __/ / / / /
 *    /___//____/\____/____/___/_/ /_/\__/\___/_/  /_/  \__,_/\___/\___(_)_/ /_/
 *                   /_____/
 */

#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_
#include "CPU_Configuration.h"

typedef enum{
	OPERATION_SUCCESS,
	START_ERROR,
	REPEAT_START_ERROR,
	SLAVE_ADDR_NOT_ACK_ERROR,
	SLAVE_DATA_NOT_ACK_ERROR,
	STOP_ERROR
}ERROR_STATES;

void I2C_Init(void);
void I2C_SetClock(UINT32_t clk);
ERROR_STATES I2C_MasterStart(void);
ERROR_STATES I2C_MasterRepeatStart(void);
ERROR_STATES I2C_SetSlaveAddressWithWrite(UINT8_t addr);
ERROR_STATES I2C_SetSlaveAddressWithRead(UINT8_t addr);
ERROR_STATES I2C_MasterWriteData(UINT8_t data);
ERROR_STATES I2C_MasterReadData(UINT8_t* val);
ERROR_STATES I2C_MasterStop(void);

#endif /* I2C_INTERFACE_H_ */
