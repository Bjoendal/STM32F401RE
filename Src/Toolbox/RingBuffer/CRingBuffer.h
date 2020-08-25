
#ifndef CBuffer_H

#define CBuffer_H

#include "types.h"


class CRingBuffer  {

public :

    CRingBuffer(void);

    virtual BOOL Add(const U8 &item);

    virtual U32 Add(const U8 items[], U32 numberOfItems);

    virtual BOOL Get(U8 &item);

    virtual U32 Get(U8 items[], U32 numberOfItems);

    void SetItsBufferArray(U8* const pBuf, const U16 sizeBuf);

    virtual U32 GetLen()const;

    void Clear(void);

private :
    U8* pBuffer;

    U16 sizeOfBuffer;

    volatile U16 nextIn;

    volatile U16 nextOut;

    volatile U16 numItems;

};


#endif

