#include "ApplicationBuilderCommon.h"

ApplicationBuilderCommon ApplicationBuilderCommon::_this;

ApplicationBuilderCommon::ApplicationBuilderCommon(void)
{
	dummy=0;
}

void ApplicationBuilderCommon::InitRelations(void)
{
	itsCLed.SetItsCGpio(&itsCGpio);

	itsCButton.SetItsCGpio(&itsCGpio);
}


BOOL ApplicationBuilderCommon::Start(void)
{
	//############################################ HAL ################################
	BOOL bReturn = TRUE;

	if(bReturn)
	{
		bReturn = itsCUart.Init(UART_CONFIG_DEFAULT);
	}

	if(bReturn)
	{
		bReturn = itsCGpio.Init();
	}

	if(bReturn)
	{
		bReturn = CTimIrqTable.Init();
	}


	//############################################ PROT ################################

	//############################################ DEV ################################

	if(bReturn)
	{
		bReturn = itsCLed.Init(LedGreenPortPin, FALSE);
	}

	if(bReturn)
	{
		bReturn = itsCButton.Init(ButtonPortPin, CButton::BAS_LOW);
	}

	//############################################ APP ################################


	return bReturn;
}

ApplicationBuilderCommon* ApplicationBuilderCommon::GetApplicationBuilder()
{
	return &_this;
}

void ApplicationBuilderCommon::Run()
{
	while(1)
	{
		if(itsCButton.State())
		{
			itsCLed.Toggle();
		}

	}

}
