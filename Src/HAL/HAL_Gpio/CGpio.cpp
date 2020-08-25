/*
 * CGpio.cpp
 *
 *  Created on: 24.08.2020
 *      Author: Lukas
 */

#include <CGpio.h>
#include "stm32f4xx.h"

CGpio::CGpio()
{

}

BOOL CGpio::Init() const
{
	return TRUE;
}

void CGpio::Set(const SPortPin_t& portPin, const BOOL b) const
{
	HAL_GPIO_WritePin(portPin.port, portPin.pin, b ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

BOOL CGpio::Get(const SPortPin_t& portPin) const
{
	return GPIO_PIN_SET == HAL_GPIO_ReadPin(portPin.port, portPin.pin);
}

