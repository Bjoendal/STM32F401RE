/*
 * TimerAdapterC.h
 *
 *  Created on: 30.03.2020
 *      Author: Lukas
 */

#ifndef SRC_IRQ_TIMERADAPTERC_H_
#define SRC_IRQ_TIMERADAPTERC_H_

#include "types.h"
#include "stm32f4xx.h"

EXTERN_C_BEGIN

enum TimerId
{
	_TIM2 = 0,
	_NUM_OF_TIMER_IDs
};

void TimX_Callbackaction(enum TimerId tim);

void SetTimerHandle(TIM_HandleTypeDef*const tim, const enum TimerId id);

EXTERN_C_END


#endif /* SRC_IRQ_TIMERADAPTERC_H_ */
