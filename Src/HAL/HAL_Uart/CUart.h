/*
 * CUart.h
 *
 *  Created on: 23.04.2020
 *      Author: Lukas
 */

#ifndef SRC_HAL_HAL_UART_CUART_H_
#define SRC_HAL_HAL_UART_CUART_H_

#include "types.h"
#include "UartConfigApp.h"
#include "IUartCallback.h"
#include "CRingBufferIT.h"


class CUart
{
public:
	CUart();

private:
	static const U8 UART_CALLBACK_COUNT = 6U;

public:

	BOOL Init(const UartConfig_t& config);

	UartOpenStatus_t Open(const UartChannel_t& channel);

	void Close(const UartChannel_t& channel);

	U16 Read(const UartChannel_t& channel, U8 * const data, const U16 numBytes);

	BOOL DataAvailible(const UartChannel_t& channel)const;

	U16 Write(const UartChannel_t& channel, U8 const * const data,	const U16 numBytes);

	void SetCallbackInterface(const UartCallbackId_t& id,	const IUartCallback& interruptCallbackInterface);

	void EnableCallback(const UartCallbackId_t& id);

	void DisableCallback(const UartCallbackId_t& id);

	U16 GetAmountOfReceivedItems(const UartChannel_t& channel)const;

	static void TxIrq1();
	static void TxIrq2();
	static void TxIrq3();

	static void RxIrq(const UartChannel uartChannel);

private:
	static const U8 channelCount = 3U;

	BOOL channelOpen[channelCount];

	UartChannel_t* channel[channelCount];

	IUartCallback* itsIUartCallback[UART_CALLBACK_COUNT];

	CRingBufferIT channelRingbufferRx[channelCount];
	CRingBufferIT channelRingbufferTx[channelCount];
};

#endif /* SRC_HAL_HAL_UART_CUART_H_ */
