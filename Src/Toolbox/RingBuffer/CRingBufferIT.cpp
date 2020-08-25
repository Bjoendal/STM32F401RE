/*
 * CRingBufferIT.cpp
 *
 *  Created on: 26.04.2020
 *      Author: Lukas
 */

#include <CRingBufferIT.h>
#include "stm32f4xx.h"

CRingBufferIT::CRingBufferIT()
{


}

BOOL CRingBufferIT::Add(const U8& item)
{
	__disable_irq();

	BOOL bRet = this->CRingBuffer::Add(item);

	__enable_irq();

	return bRet;
}

U32 CRingBufferIT::Add(const U8 items[], U32 numberOfItems)
{
	__disable_irq();

	U32 u32Ret = this->CRingBuffer::Add(items, numberOfItems);

	__enable_irq();

	return u32Ret;
}

BOOL CRingBufferIT::Get(U8& item)
{
	__disable_irq();

	BOOL bRet = this->CRingBuffer::Get(item);

	__enable_irq();

	return bRet;
}

U32 CRingBufferIT::Get(U8 items[], U32 numberOfItems)
{
	__disable_irq();

	U32 u32Ret = this->CRingBuffer::Get(items, numberOfItems);

	__enable_irq();

	return u32Ret;
}

U32 CRingBufferIT::GetLen() const
{
	__disable_irq();

	U32 u32Ret = this->CRingBuffer::GetLen();

	__enable_irq();

	return u32Ret;
}
