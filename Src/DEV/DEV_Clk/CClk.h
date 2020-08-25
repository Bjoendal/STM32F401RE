/*
 * CClk.h
 *
 *  Created on: 05.04.2020
 *      Author: Lukas
 */

#ifndef SRC_HAL_CCLK_H_
#define SRC_HAL_CCLK_H_

#include "types.h"

class CClk
{
public:
	CClk();

	BOOL Init()const;

	U32 GetMs() const;


	void SetLength(const U32 u32Len);
	U32 GetLeft()const;
	U32 GetLen()const;
	U32 GetStart()const;

private:
	U32 u32StartTime;
	U32 u32Length;
};

#endif /* SRC_HAL_CCLK_H_ */
