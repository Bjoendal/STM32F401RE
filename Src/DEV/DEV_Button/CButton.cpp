/*
 * CButton.cpp
 *
 *  Created on: 24.08.2020
 *      Author: Lukas
 */

#include "CButton.h"

CButton::CButton()
{
	itsPortPin	= NULL;
	itsCGpio	= NULL;
	bLastState	= FALSE;
	itsActiveState = BAS_HIGH;
}

BOOL CButton::Init(const SPortPin_t& portPin, const EButtonActiveState activeState)
{
	itsPortPin = &portPin;

	itsActiveState = activeState;

	return (NULL != itsCGpio) && itsClk.Init();
}

void CButton::SetItsCGpio(CGpio* const gpio)
{
	itsCGpio = gpio;
}

BOOL CButton::State()
{
	BOOL bReturn = FALSE;

	if(bLastState)
	{
		bLastState = PinState();

		if(!bLastState)
		{
			itsClk.SetLength(50UL);
		}
	}
	else
	{
		if(!itsClk.GetLeft())
		{
			bLastState = PinState();
			bReturn = bLastState;
		}
		else
		{
			bLastState = PinState();
		}
	}

	return bReturn;
}

BOOL CButton::PinState()
{
	if(BAS_HIGH == itsActiveState)
	{
		return itsCGpio->Get(*itsPortPin);
	}
	else
	{
		return !itsCGpio->Get(*itsPortPin);
	}
}
