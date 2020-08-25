/*
 * CLed.h
 *
 *  Created on: 24.08.2020
 *      Author: Lukas
 */

#ifndef DEV_DEV_LED_CLED_H_
#define DEV_DEV_LED_CLED_H_

#include "CGpio.h"

class CLed
{
public:
	CLed();

	void SetItsCGpio(CGpio*const gpio);
	BOOL Init(const SPortPin_t& portPin, const BOOL bLedInitState);

	void On();
	void Off();
	void SetState(const BOOL state);
	void Toggle();

	BOOL GetState()const;

private:
	const SPortPin_t* itsPortPin;

	CGpio* itsCGpio;
};

#endif /* DEV_DEV_LED_CLED_H_ */
