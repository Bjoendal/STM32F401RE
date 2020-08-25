/*
 * CGpio.h
 *
 *  Created on: 24.08.2020
 *      Author: Lukas
 */

#ifndef HAL_HAL_GPIO_CGPIO_H_
#define HAL_HAL_GPIO_CGPIO_H_

#include "GpioConfigApp.h"

class CGpio {
public:
	CGpio();

	BOOL Init()const;

	void Set(const SPortPin_t& portPin, const BOOL b)const;
	BOOL Get(const SPortPin_t& portPin)const;

};

#endif /* HAL_HAL_GPIO_CGPIO_H_ */
