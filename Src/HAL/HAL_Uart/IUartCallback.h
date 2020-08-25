/*
 * IUartCallback.h
 *
 *  Created on: 24.04.2020
 *      Author: Lukas
 */

#ifndef SRC_HAL_HAL_UART_IUARTCALLBACK_H_
#define SRC_HAL_HAL_UART_IUARTCALLBACK_H_

class IUartCallback
{
public:
	IUartCallback();
	virtual void Do() = 0;
};

#endif /* SRC_HAL_HAL_UART_IUARTCALLBACK_H_ */
