/***
 *       __  _____    ____  ______   ____
 *      / / / /   |  / __ \/_  __/  / __ \_________  ____ __________ _____ ___   _____
 *     / / / / /| | / /_/ / / /    / /_/ / ___/ __ \/ __ `/ ___/ __ `/ __ `__ \ / ___/
 *    / /_/ / ___ |/ _, _/ / /    / ____/ /  / /_/ / /_/ / /  / /_/ / / / / / // /__
 *    \____/_/  |_/_/ |_| /_/____/_/   /_/   \____/\__, /_/   \__,_/_/ /_/ /_(_)___/
 *                         /_____/                /____/
 */
#include "UART_Private.h"
#include "UART_Config.h"
#include "UART_Interface.h"
#include "DIO_Interface.h"

void UART_voidInit(){

volatile UINT8_t UCSRC_MAP=0,UCSRB_MAP=0;

DIO_SetPin_Direction(DIO_PORTD,DIO_PIN0,DIO_INPUT);//RX as input
DIO_SetPin_Direction(DIO_PORTD,DIO_PIN1,DIO_OUTPUT);//TX as output

SET_BIT(UCSRC_MAP,7);

#if RXEN == RX_EN
SET_BIT(UCSRB_MAP,4);
#elif RX_EN == RX_DS
CLR_BIT(UCSRB_MAP,4);
#else
#error "ERROR"
#endif /*Receiver MODE*/

#if TXEN == TX_EN
SET_BIT(UCSRB_MAP,3);
#elif TXEN == TX_DS
CLR_BIT(UCSRB_MAP,3);
#else
#error "ERROR"
#endif /*Transmitter MODE*/



#if	UMSEL == USART_Asynch
CLR_BIT(UCSRC_MAP,6);
#elif UMSEL == USART_Synch
SET_BIT(UCSRC_MAP,6);
#else
#error "ERROR"
#endif /*Sync Mode Select*/

#if	UPM == PM_DS
CLR_BIT(UCSRC_MAP,5);
CLR_BIT(UCSRC_MAP,4);
#elif UPM == PM_EVEN
SET_BIT(UCSRC_MAP,5);
CLR_BIT(UCSRC_MAP,4);
#elif UPM == PM_ODD
SET_BIT(UCSRC_MAP,5);
SET_BIT(UCSRC_MAP,4);
#else

#error "ERROR"
#endif /*Parity Mode Select*/

#if	USBS == SB_1BIT
CLR_BIT(UCSRC_MAP,3);
#elif USBS == SB_2BIT
SET_BIT(UCSRC_MAP,3);
#else
#error "ERROR"
#endif /*Stop Bit(s) Select*/


#if	UCSZ == UCSZ_5BIT
CLR_BIT(UCSRB_MAP,2);
CLR_BIT(UCSRC_MAP,2);
CLR_BIT(UCSRC_MAP,1);
#elif UCSZ == UCSZ_6BIT
CLR_BIT(UCSRB_MAP,2);
CLR_BIT(UCSRC_MAP,2);
SET_BIT(UCSRC_MAP,1);
#elif UCSZ == UCSZ_7BIT
CLR_BIT(UCSRB_MAP,2);
SET_BIT(UCSRC_MAP,2);
CLR_BIT(UCSRC_MAP,1);
#elif UCSZ == UCSZ_8BIT
CLR_BIT(UCSRB_MAP,2);
SET_BIT(UCSRC_MAP,2);
SET_BIT(UCSRC_MAP,1);
#elif UCSZ == UCSZ_9BIT
SET_BIT(UCSRB_MAP,2);
SET_BIT(UCSRC_MAP,2);
SET_BIT(UCSRC_MAP,1);
#else

#error "ERROR"
#endif /*Character Size Select*/

#if RXCIE == RXCI_EN
SET_BIT(UCSRA_MAP,7);
#elif RXCIE == RXCI_DS
CLR_BIT(UCSRB_MAP,7);
#else
#error "ERROR"
#endif /*RX Complete Interrupt MODE*/

#if TXCIE == TXCI_EN
SET_BIT(UCSRA_MAP,6);
#elif TXCIE == TXCI_DS
CLR_BIT(UCSRB_MAP,6);
#else
#error "ERROR"
#endif /* TX Complete Interrupt MODE*/

#if UDRIE == UDRI_EN
SET_BIT(UCSRA_MAP,5);
#elif UDRIE == UDRI_DS
CLR_BIT(UCSRB_MAP,5);
#else
#error "ERROR"
#endif /*UDRE Flag MODE*/


UCSRC |= UCSRC_MAP;
UCSRB |= UCSRB_MAP;
}

/*void UART_voidTransmitByte_synch(UINT8_t Copy_data){

}
UINT8_t UART_voidRecieverByte_synch(void){

}*/
void UART_voidTransmitByte_synch(UINT8_t Copy_data){

}

UINT8_t UART_u8GetUDRValue(void){
	UINT8_t dataReceived = 0;
	while(GET_BIT(UCSRA, 7) != 1);
	dataReceived = UDR;
	return dataReceived;
}
void UART_voidSetBaudRate(UINT32_t Copy_u32BoudRate){
	UINT16_t UBRR_Val = 0;
	UBRR_Val = ((16000000) / (16 * Copy_u32BoudRate)) - 1;
	UBRRL = UBRR_Val;
	UBRRH = UBRR_Val >> 8;
}

void UART_voidSendString (const UINT8_t Copy_StrPtr){
	UDR = Copy_StrPtr;
	while(GET_BIT(UCSRA, 6) != 1);
}
void UART_voidRecString (UINT8_t *Copy_StrPtr){

}
