#include <CRingBuffer.h>

CRingBuffer::CRingBuffer(void) : pBuffer(NULL), sizeOfBuffer(0U), nextIn(0U), nextOut(0U), numItems(0U)
{
}

BOOL CRingBuffer::Add(const U8 &item)
{
	BOOL retVal = FALSE;
	if ((NULL != pBuffer))
	{
		if (numItems < sizeOfBuffer)
		{
			pBuffer[nextIn] = item;

			nextIn++;
			numItems++;


			if (nextIn >= sizeOfBuffer)
			{
				nextIn = 0U;
			}
			retVal = TRUE;
		}
	}
	return retVal;

}

U32 CRingBuffer::Add(const U8 items[], U32 numberOfItems)
{
	U32 byteCount = 0U;
	if ((NULL != pBuffer))
	{
		while (byteCount < numberOfItems)
		{
			if (numItems < sizeOfBuffer)
			{

				pBuffer[nextIn] = items[byteCount];

				byteCount++;
				nextIn++;
				numItems++;

				if (nextIn >= sizeOfBuffer)
				{
					nextIn = 0U;
				}
			}
			else
			{
				break;
			}
		}
	}
	return byteCount;
}

BOOL CRingBuffer::Get(U8 &item)
{
	BOOL retVal = FALSE;
	if ((NULL != pBuffer))
	{

		if (numItems > 0U)
		{
			item = pBuffer[nextOut];

			nextOut++;
			numItems--;

			if (nextOut >= sizeOfBuffer)
			{
				nextOut = 0U;
			}
			retVal = TRUE;
		}
	}
	return retVal;
}

U32 CRingBuffer::Get(U8 items[], U32 numberOfItems)
{
	U32 byteCount = 0U;
	if ((NULL != pBuffer))
	{
		while (byteCount < numberOfItems)
		{
			if (numItems > 0U)
			{
				items[byteCount] = pBuffer[nextOut];

				byteCount++;
				nextOut++;
				numItems--;

				if (nextOut >= sizeOfBuffer)
				{
					nextOut = 0U;
				}
			}
			else
			{
				break;
			}
		}
	}
	return byteCount;
}

void CRingBuffer::SetItsBufferArray(U8* const pBuf, const U16 sizeBuf)
{
	pBuffer = pBuf;
	sizeOfBuffer = sizeBuf;
	Clear();
}

U32 CRingBuffer::GetLen() const
{
	return numItems;
}

void CRingBuffer::Clear(void)
{
	numItems = 0U;
	nextIn = 0U;
	nextOut = 0U;
}

