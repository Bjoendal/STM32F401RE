/*
 * CTimIrqTable.h
 *
 *  Created on: 30.03.2020
 *      Author: Lukas
 */

#ifndef IRQ_CTIMIRQTABLE_H_
#define IRQ_CTIMIRQTABLE_H_

#include "types.h"
#include "stm32f4xx.h"
#include "TimerAdapterC.h"

class ITimCallback
{
public:
	ITimCallback();

	virtual void Callbackaction() = 0;
};

class _CTimIrqTable
{
public:
	_CTimIrqTable();

	BOOL Init();

	void SetITimCallback(ITimCallback*const timCb, const TimerId timId);

	void SetTimHandle(TIM_HandleTypeDef*const timHandle, const TimerId timId);

	static const U8 NUM_OF_CALLBACKS = static_cast<U8>(_NUM_OF_TIMER_IDs);


	BOOL StartTimer(const TimerId timId);
	void StopTimer(const TimerId timId);

	ITimCallback* Callbacks[NUM_OF_CALLBACKS];

private:
	TIM_HandleTypeDef* TimerHandles[NUM_OF_CALLBACKS];

	U32 u32TimClk;
};

extern _CTimIrqTable CTimIrqTable;

#endif /* IRQ_CTIMIRQTABLE_H_ */
