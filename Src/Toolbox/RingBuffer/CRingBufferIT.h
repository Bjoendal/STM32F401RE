/*
 * CRingBufferIT.h
 *
 *  Created on: 26.04.2020
 *      Author: Lukas
 */

#ifndef SRC_TOOLBOX_RINGBUFFER_CRINGBUFFERIT_H_
#define SRC_TOOLBOX_RINGBUFFER_CRINGBUFFERIT_H_

#include <CRingBuffer.h>

class CRingBufferIT: public CRingBuffer
{
public:
	CRingBufferIT();

    BOOL Add(const U8 &item);

    U32 Add(const U8 items[], U32 numberOfItems);

    BOOL Get(U8 &item);

    U32 Get(U8 items[], U32 numberOfItems);

    U32 GetLen()const;

};

#endif /* SRC_TOOLBOX_RINGBUFFER_CRINGBUFFERIT_H_ */
