/*
 * CButton.h
 *
 *  Created on: 24.08.2020
 *      Author: Lukas
 */

#ifndef DEV_DEV_BUTTON_CBUTTON_H_
#define DEV_DEV_BUTTON_CBUTTON_H_

#include "CGpio.h"
#include "CClk.h"

class CButton
{
public:

	enum EButtonActiveState
	{
		BAS_HIGH,
		BAS_LOW
	};

	CButton();

	void SetItsCGpio(CGpio*const gpio);

	BOOL Init(const SPortPin_t& portPin, const EButtonActiveState activeState);

	BOOL State();

private:
	BOOL PinState();

private:
	CClk itsClk;
	CGpio* itsCGpio;

	const SPortPin_t* itsPortPin;

	EButtonActiveState itsActiveState;

	BOOL bLastState;

};

#endif /* DEV_DEV_BUTTON_CBUTTON_H_ */
