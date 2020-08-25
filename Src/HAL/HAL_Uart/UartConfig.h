/*
 * UartConfig.h
 *
 *  Created on: 23.04.2020
 *      Author: Lukas
 */

#ifndef SRC_HAL_HAL_UART_UARTCONFIG_H_
#define SRC_HAL_HAL_UART_UARTCONFIG_H_
#include "types.h"
#include "stm32f4xx_hal.h"

typedef struct UartConfig_t
{
	U16 dummy;
}
UartConfig_t;

enum UartChannel
{
	UART_CHANNEL_1 = 0,
	UART_CHANNEL_2,
	UART_CHANNEL_6
};


typedef struct UartChannel_t
{
	UartChannel channel;
	UART_HandleTypeDef*const uartHandle;
	U8* u8TxBuffer;
	U16 u16TxBufferLen;
	U8* u8RxBuffer;
	U16 u16RxBufferLen;
	U8 u8Buffer[2];	//nicht anfassen!
}
UartChannel_t;

enum UartOpenStatus_t
{
	UART_OST_SUCCESS,
	UART_OST_FAILED
};

enum UartCallbackId_t
{
	UART_1_TX = 0,
	UART_2_TX,
	UART_6_TX,
	UART_1_RX,
	UART_2_RX,
	UART_6_RX
};

#endif /* SRC_HAL_HAL_UART_UARTCONFIG_H_ */
