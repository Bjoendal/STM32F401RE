/*
 * AdapterC.cpp
 *
 *  Created on: 30.03.2020
 *      Author: Lukas
 */
#include "AdapterC.h"
#include "ApplicationBuilderCommon.h"

EXTERN_C_BEGIN

void CreateApplication()
{
	ApplicationBuilderCommon*const itsApplicationBuilder = ApplicationBuilderCommon::GetApplicationBuilder();

	itsApplicationBuilder->InitRelations();

	if(itsApplicationBuilder->Start())
	{
		itsApplicationBuilder->Run();
	}
	else
	{
		while(1){}
	}
}

EXTERN_C_END


