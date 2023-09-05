/***
 *        ___    ____  ______     ____
 *       /   |  / __ \/ ____/    / __ \_________  ____ __________ _____ ___   _____
 *      / /| | / / / / /        / /_/ / ___/ __ \/ __ `/ ___/ __ `/ __ `__ \ / ___/
 *     / ___ |/ /_/ / /___     / ____/ /  / /_/ / /_/ / /  / /_/ / / / / / // /__
 *    /_/  |_/_____/\____/____/_/   /_/   \____/\__, /_/   \__,_/_/ /_/ /_(_)___/
 *                      /_____/                /____/
 */
#include "ADC_Private.h"
#include "ADC_Interface.h"

ERROR_STATE ADC_Initialize(){
	CLR_BIT(ADC_REF_voltage,REF_BIT1);SET_BIT(ADC_REF_voltage,REF_BIT0);
	SET_BIT(ADC_CNTR_State,ADC_EN_BIT);
	SET_BIT(ADC_CNTR_State,ADC_PRESCALER_BIT2);SET_BIT(ADC_CNTR_State,ADC_PRESCALER_BIT1);SET_BIT(ADC_CNTR_State,ADC_PRESCALER_BIT0);
	return SUCCESS;
}

ERROR_STATE ADC_Read(ADC_PIN channel,UINT16_t* adc_value){
	ADC_REF_voltage &= 0XF0;
	ADC_REF_voltage |= channel;
	CLR_BIT(ADC_CNTR_State,ADC_INTERRUPT_EN);
	CLR_BIT(ADC_CNTR_State,ADC_AUTO_TRIGGER_EN);
	SET_BIT(ADC_CNTR_State,ADC_START_CONVERSION);
	while(GET_BIT(ADC_CNTR_State,ADC_NORMAL_FLAG));
	*adc_value = ADCL;
	return SUCCESS;
}
