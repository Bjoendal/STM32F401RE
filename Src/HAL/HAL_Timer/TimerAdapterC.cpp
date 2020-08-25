/*
 * TimerAdapterC.cpp
 *
 *  Created on: 30.03.2020
 *      Author: Lukas
 */

#include "TimerAdapterC.h"
#include "CTimIrqTable.h"
EXTERN_C_BEGIN

void TimX_Callbackaction(enum TimerId tim)
{
	CTimIrqTable.Callbacks[tim]->Callbackaction();
}

void SetTimerHandle(TIM_HandleTypeDef*const tim, const enum TimerId id)
{
	CTimIrqTable.SetTimHandle(tim, id);
}

EXTERN_C_END
