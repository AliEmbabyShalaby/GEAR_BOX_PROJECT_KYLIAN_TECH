/***
 *       __  _____    ____  ______   ____      __            ____                  __
 *      / / / /   |  / __ \/_  __/  /  _/___  / /____  _____/ __/___ _________    / /_
 *     / / / / /| | / /_/ / / /     / // __ \/ __/ _ \/ ___/ /_/ __ `/ ___/ _ \  / __ \
 *    / /_/ / ___ |/ _, _/ / /    _/ // / / / /_/  __/ /  / __/ /_/ / /__/  __/ / / / /
 *    \____/_/  |_/_/ |_| /_/____/___/_/ /_/\__/\___/_/  /_/  \__,_/\___/\___(_)_/ /_/
 *                         /_____/
 */
#ifndef UART_UART_INTERFACE_H_
#define UART_UART_INTERFACE_H_

void UART_voidInit(void);

/*void UART_voidTransmitByte_synch(UINT8_t Copy_data);
UINT8_t UART_voidRecieverByte_synch(void);*/

UINT8_t UART_u8GetUDRValue(void);
void UART_voidSetBaudRate(UINT32_t Copy_u32BoudRate);

void UART_voidSendString (const UINT8_t Copy_StrPtr);
void UART_voidRecString (UINT8_t *Copy_StrPtr);

void UART_voidRegisterCallback(UINT8_t Copy_UART_Interrupt ,void (*fptr)(UINT8_t));

#endif /* UART_UART_INTERFACE_H_ */
