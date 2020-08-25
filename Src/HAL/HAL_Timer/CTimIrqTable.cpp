/*
 * CTimIrqTable.cpp
 *
 *  Created on: 30.03.2020
 *      Author: Lukas
 */

#include <CTimIrqTable.h>



_CTimIrqTable CTimIrqTable;


_CTimIrqTable::_CTimIrqTable()
{
	u32TimClk = 0UL;

	for(U8 i = 0U; i < NUM_OF_CALLBACKS; i++)
	{
		Callbacks[i] = NULL;
		TimerHandles[i] = NULL;
	}
}

ITimCallback::ITimCallback() {}

void _CTimIrqTable::SetITimCallback(ITimCallback* const timCb, const TimerId timId)
{
	if(timId < NUM_OF_CALLBACKS)
	{
		Callbacks[timId] = timCb;
	}
}

void _CTimIrqTable::SetTimHandle(TIM_HandleTypeDef* const timHandle, const TimerId timId)
{
	if(timId < NUM_OF_CALLBACKS)
	{
		TimerHandles[timId] = timHandle;
	}
}

BOOL _CTimIrqTable::StartTimer(const TimerId timId)
{
	if(TimerHandles[timId] != NULL)
	{
		return HAL_OK == HAL_TIM_Base_Start_IT(TimerHandles[timId]);
	}
	return FALSE;
}

BOOL _CTimIrqTable::Init()
{
	u32TimClk = HAL_RCC_GetPCLK1Freq();

	return 0UL != u32TimClk;
}

void _CTimIrqTable::StopTimer(const TimerId timId)
{
	if(TimerHandles[timId] != NULL)
	{
		HAL_TIM_Base_Stop_IT(TimerHandles[timId]);
	}
}
