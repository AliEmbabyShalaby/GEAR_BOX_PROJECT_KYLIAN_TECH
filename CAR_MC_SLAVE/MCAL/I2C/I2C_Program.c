/***
 *        _______   ______     ____
 *       /  _/__ \ / ____/    / __ \_________  ____ __________ _____ ___   _____
 *       / / __/ // /        / /_/ / ___/ __ \/ __ `/ ___/ __ `/ __ `__ \ / ___/
 *     _/ / / __// /___     / ____/ /  / /_/ / /_/ / /  / /_/ / / / / / // /__
 *    /___//____/\____/____/_/   /_/   \____/\__, /_/   \__,_/_/ /_/ /_(_)___/
 *                   /_____/                /____/
 */

#include "I2C_Config.h"
#include "I2C_Interface.h"
#include "I2C_Private.h"
#include "DIO_Interface.h"

void I2C_Init(){
	UINT8_t TWCR_setting = 0;
	UINT8_t TWSR_setting = 0;
	
	/*Enable or Disable I2C*/
	#if I2C_MODE == I2C_DS
	
	CLR_BIT(TWCR_setting, TWCR_TWEN);
	
	#elif I2C_MODE == I2C_EN
	
	SET_BIT(TWCR_setting, TWCR_TWEN);
	
	#endif /*I2C_MODE*/
	/*Enable or Disable I2C Interrupt*/
	#if I2C_INT_MODE == I2C_INT_DS
	
	CLR_BIT(TWCR_setting, TWCR_TWIE);
	
	#elif I2C_INT_MODE == I2C_INT_EN
	
	SET_BIT(TWCR_setting, TWCR_TWIE);
	Global_Interrupt_Enable();
	
	#endif /*I2C_INT_MODE*/
	/*Set I2C prescaler*/
	#if I2C_PRESCALE == I2C_PRESCALE_1
	
	CLR_BIT(TWSR_setting, TWSR_TWPS0);
	CLR_BIT(TWSR_setting, TWSR_TWPS1);
	
	#elif I2C_PRESCALE == I2C_PRESCALE_4
	
	SET_BIT(TWSR_setting, TWSR_TWPS0);
	CLR_BIT(TWSR_setting, TWSR_TWPS1);
	
	#elif I2C_PRESCALE == I2C_PRESCALE_16

	CLR_BIT(TWSR_setting, TWSR_TWPS0);
	SET_BIT(TWSR_setting, TWSR_TWPS1);
	
	#elif I2C_PRESCALE == I2C_PRESCALE_64
	
	SET_BIT(TWSR_setting, TWSR_TWPS0);
	SET_BIT(TWSR_setting, TWSR_TWPS1);
	
	#endif /*I2C_PRESCALE*/
	/*Load settings into respective registers*/
	TWSR = TWSR_setting;
	TWCR = TWCR_setting;
}


void I2C_SetClock(UINT32_t clk){
	TWBR = (UINT8_t)(((F_CPU / clk) - 16) / (2 * I2C_PRESCALE));
}


ERROR_STATES I2C_MasterStart(){
	ERROR_STATES error_state = OPERATION_SUCCESS;
	/*Enable I2C and send a start condition*/
	TWCR = (1 << TWCR_TWINT) | (1 << TWCR_TWSTA) | (1 << TWCR_TWEN);
	/*Wait for hardware to finish*/
	while(!GET_BIT(TWCR, TWCR_TWINT));
	/*Check for feedback status*/
	if((TWSR & 0xF8) != START_ACK){
		error_state = START_ERROR;
	}else{
		/*Do nothing*/
	}
	return error_state;
}

ERROR_STATES I2C_MasterRepeatStart(){
	ERROR_STATES error_state = OPERATION_SUCCESS;
	/*Enable I2C and send a start condition*/
	TWCR = (1 << TWCR_TWINT) | (1 << TWCR_TWSTA) | (1 << TWCR_TWEN);
	/*Wait for hardware to finish*/
	while(!GET_BIT(TWCR, TWCR_TWINT));
	/*Check for feedback status*/
	if((TWSR & 0xF8) != REP_START_ACK){
		error_state = REPEAT_START_ERROR;
	}else{
		/*Do nothing*/
	}
	return error_state;
}

UINT8_t I2C_SetSlaveAddressWithWrite(UINT8_t addr){
	ERROR_STATES error_state = OPERATION_SUCCESS;
	/*Load data register with slave address + write*/
	TWDR = addr;
	/*Enable I2C and signal hardware to start operation*/
	TWCR = (1 << TWCR_TWINT) | (1 << TWCR_TWEN);
	/*Wait for hardware to finish*/
	while(!GET_BIT(TWCR, TWCR_TWINT));
	/*Check for feedback status*/
	if((TWSR & 0xF8) != MSTR_ADDR_AND_W_ACK){
		error_state = SLAVE_ADDR_NOT_ACK_ERROR;
		}else{
		/*Do nothing*/
	}
	return error_state;
}

UINT8_t I2C_SetSlaveAddressWithRead(UINT8_t addr){
	ERROR_STATES error_state = OPERATION_SUCCESS;
	/*Load data register with slave address + read*/
	TWDR = (addr | 1);
	/*Enable I2C and signal hardware to start operation*/
	TWCR = (1 << TWCR_TWINT) | (1 << TWCR_TWEN);
	/*Wait for hardware to finish*/
	while(!GET_BIT(TWCR, TWCR_TWINT));
	/*Check for feedback status*/
	if((TWSR & 0xF8) != MSTR_ADDR_AND_R_ACK){
		error_state = SLAVE_ADDR_NOT_ACK_ERROR;
		}else{
		/*Do nothing*/
	}
	return error_state;
}

UINT8_t I2C_MasterWriteData(UINT8_t data){
	ERROR_STATES error_state = OPERATION_SUCCESS;
	/*Load data register with user data*/
	TWDR = data;
	/*Enable I2C and signal hardware to start operation*/
	TWCR = (1 << TWCR_TWINT) | (1 << TWCR_TWEN);
	/*Wait for hardware to finish*/
	while(!GET_BIT(TWCR, TWCR_TWINT));
	/*Check for feedback status*/
	if((TWSR & 0xF8) != MSTR_DATA_TX_ACK){
		error_state = SLAVE_DATA_NOT_ACK_ERROR;
		}else{
		/*Do nothing*/
	}
	return error_state;
}

UINT8_t I2C_MasterReadData(UINT8_t *val){
	ERROR_STATES error_state = OPERATION_SUCCESS;
	/*Enable I2C and enable master acknowledge signal hardware to start operation*/
	TWCR = (1 << TWCR_TWINT) | (1 << TWCR_TWEA) | (1 << TWCR_TWEN);
	/*Wait for hardware to finish*/
	while(!GET_BIT(TWCR, TWCR_TWINT));
	/*Read data*/
	*val = TWDR;
	/*Check for feedback status*/
	if((TWSR & 0xF8) != MSTR_DATA_RX_ACK){
		error_state = SLAVE_DATA_NOT_ACK_ERROR;
		}else{
		/*Do nothing*/
	}
	return error_state;
}

UINT8_t I2C_MasterStop(){
	ERROR_STATES error_state = OPERATION_SUCCESS;
	/*Enable I2C and send a start condition*/
	TWCR = (1 << TWCR_TWINT) | (1 << TWCR_TWSTO) | (1 << TWCR_TWEN);
	/*Wait for hardware to finish*/
	while(GET_BIT(TWCR, TWCR_TWINT));
	/*Check for feedback status*/
	if((TWSR & 0xF8) == BUS_ERROR){
		error_state = STOP_ERROR;
		}else{
		/*Do nothing*/
	}
	return error_state;
}
