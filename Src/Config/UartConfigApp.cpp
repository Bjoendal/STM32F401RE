/*
 * UartConfigApp.cpp
 *
 *  Created on: 24.04.2020
 *      Author: Lukas
 */

#include <UartConfigApp.h>


extern UART_HandleTypeDef huart2;

U8 rxBufferChannel2[500];
U8 txBufferChannel2[500];


UartChannel_t UART_CHANNEL_2_57600 =
{
		UART_CHANNEL_2,
		&huart2,
		txBufferChannel2,
		static_cast<U16>(sizeof(txBufferChannel2)/sizeof(*txBufferChannel2)),
		rxBufferChannel2,
		static_cast<U16>(sizeof(rxBufferChannel2)/sizeof(*rxBufferChannel2))
};
