/*
 * GpioConfigApp.h
 *
 *  Created on: 24.08.2020
 *      Author: Lukas
 */

#ifndef CONFIG_GPIOCONFIGAPP_H_
#define CONFIG_GPIOCONFIGAPP_H_

#include "GpioConfig.h"

const SPortPin_t 	ButtonPortPin 	= { Button_GPIO_Port, Button_Pin };
const SPortPin_t	LedGreenPortPin	= { LED_Gruen_GPIO_Port, LED_Gruen_Pin };

#endif /* CONFIG_GPIOCONFIGAPP_H_ */
