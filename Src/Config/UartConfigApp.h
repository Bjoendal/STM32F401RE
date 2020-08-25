/*
 * UartConfigApp.h
 *
 *  Created on: 24.04.2020
 *      Author: Lukas
 */

#ifndef SRC_CONFIG_UARTCONFIGAPP_H_
#define SRC_CONFIG_UARTCONFIGAPP_H_

#include "UartConfig.h"
#include "stm32f401xe.h"




extern U8 rxBufferChannel2[500];
extern U8 txBufferChannel2[500];

const UartConfig_t UART_CONFIG_DEFAULT = {7353}; //ESEL

extern UartChannel_t UART_CHANNEL_2_57600;

#endif /* SRC_CONFIG_UARTCONFIGAPP_H_ */
