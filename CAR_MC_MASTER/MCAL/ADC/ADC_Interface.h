/***
 *        ___    ____  ______     ____      __            ____                  __
 *       /   |  / __ \/ ____/    /  _/___  / /____  _____/ __/___ _________    / /_
 *      / /| | / / / / /         / // __ \/ __/ _ \/ ___/ /_/ __ `/ ___/ _ \  / __ \
 *     / ___ |/ /_/ / /___     _/ // / / / /_/  __/ /  / __/ /_/ / /__/  __/ / / / /
 *    /_/  |_/_____/\____/____/___/_/ /_/\__/\___/_/  /_/  \__,_/\___/\___(_)_/ /_/
 *                      /_____/
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

/************************************************************************/
/*                         Data Definitions:                            */
/************************************************************************/

#define ADC_REF_voltage			ADMUX
#define ADC_CNTR_State			ADCSRA
#define ADC_SPECIAL_REG			SFIOR

#define REF_BIT0				REFS0
#define REF_BIT1				REFS1

#define ADC_EN_BIT				ADEN
#define ADC_START_CONVERSION	ADSC

#define ADC_PRESCALER_BIT0		ADPS0
#define ADC_PRESCALER_BIT1		ADPS1
#define ADC_PRESCALER_BIT2		ADPS2
#define ADC_INTERRUPT_EN		ADIE

#define ADC_NORMAL_FLAG			ADSC
//ADC_READ_VALUE

#define ADC_INTERRUPT_EN		ADIE
#define ADC_AUTO_TRIGGER_EN		ADATE

typedef enum{
ADC_PIN0,
ADC_PIN1,
ADC_PIN2,
ADC_PIN3,
ADC_PIN4,
ADC_PIN5,
ADC_PIN6,
ADC_PIN7
}ADC_PIN;


/************************************************************************/
/*                      Functions Prototypes                            */
/************************************************************************/

ERROR_STATE ADC_Initialize();
ERROR_STATE ADC_Read(ADC_PIN channel,UINT16_t* adc_value);
ERROR_STATE ADC_INT_Read(ADC_PIN channel);


#endif /* ADC_INTERFACE_H_ */
