/*
 * CClk.cpp
 *
 *  Created on: 05.04.2020
 *      Author: Lukas
 */

#include "CClk.h"
#include "stm32f4xx.h"

CClk::CClk()
{
	u32Length 		= 0UL;
	u32StartTime 	= 0UL;
}

BOOL CClk::Init() const
{
	return TRUE;
}

U32 CClk::GetMs() const
{
	return HAL_GetTick();
}

void CClk::SetLength(const U32 u32Len)
{
	u32Length = u32Len;
	u32StartTime = GetMs();
}

U32 CClk::GetLeft() const
{
	const U32 u32CurrentTime = GetMs();

	if((u32Length + u32StartTime) > u32CurrentTime)
	{
		return (u32Length + u32StartTime) - u32CurrentTime;
	}
	else
	{
		return 0UL;
	}
}

U32 CClk::GetLen() const
{
	return u32Length;
}

U32 CClk::GetStart() const
{
	return u32StartTime;
}
