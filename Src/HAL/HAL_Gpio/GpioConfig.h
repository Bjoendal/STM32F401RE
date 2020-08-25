/*
 * GpioConfig.h
 *
 *  Created on: 24.08.2020
 *      Author: Lukas
 */

#ifndef HAL_HAL_GPIO_GPIOCONFIG_H_
#define HAL_HAL_GPIO_GPIOCONFIG_H_

#include "types.h"


#include "main.h"
#include "stm32f4xx_hal.h"


typedef struct
{
	GPIO_TypeDef*const port;
	const U16 pin;
} SPortPin_t;

#endif /* HAL_HAL_GPIO_GPIOCONFIG_H_ */
