/*
 * CLed.cpp
 *
 *  Created on: 24.08.2020
 *      Author: Lukas
 */

#include <CLed.h>

CLed::CLed()
{
	itsPortPin 	= NULL;
	itsCGpio	= NULL;
}

void CLed::SetItsCGpio(CGpio* const gpio)
{
	itsCGpio = gpio;
}

BOOL CLed::Init(const SPortPin_t& portPin, const BOOL bLedInitState)
{
	itsPortPin = &portPin;

	if(NULL != itsCGpio)
	{
		itsCGpio->Set(portPin, bLedInitState);

		return TRUE;
	}

	return FALSE;
}

void CLed::On()
{
	itsCGpio->Set(*itsPortPin, TRUE);
}

void CLed::Off()
{
	itsCGpio->Set(*itsPortPin, FALSE);
}

void CLed::SetState(const BOOL state)
{
	itsCGpio->Set(*itsPortPin, state);
}

BOOL CLed::GetState() const
{
	return itsCGpio->Get(*itsPortPin);
}

void CLed::Toggle()
{
	if(GetState())
	{
		Off();
	}
	else
	{
		On();
	}
}
