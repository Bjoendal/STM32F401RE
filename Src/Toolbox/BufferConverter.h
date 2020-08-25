/*
 * EndianessConerter.h
 *
 *  Created on: 27.04.2020
 *      Author: Lukas
 */

#ifndef SRC_TOOLBOX_ENDIANESSCONERTER_H_
#define SRC_TOOLBOX_ENDIANESSCONERTER_H_

#include "types.h"

enum EEndianness
{
	ENDIAN_LITTLE,	//low byte first
	ENDIAN_BIG		//high byte firs
};


 BOOL 	GetBOOL(const U8 pu8Buffer[], const U16 u16Index);
 void 	SetBOOL(const BOOL b, U8 pu8Buffer[],  const U16 u16Index);

 U8 	GetU8(const U8 pu8Buffer[], const U16 u16Index);
 void 	SetU8(const U8 u8, U8 pu8Buffer[], const U16 u16Index);

 S8 	GetS8(const U8 pu8Buffer[], U16 u16Index);
 void 	SetS8(const S8 s8, U8 pu8Buffer[], const U16 u16Index);

 CHAR 	GetCHAR(const U8 pu8Buffer[], const U16 u16Index);
 void 	SetCHAR(const CHAR c, U8 pu8Buffer[], const U16 u16Index);

 U16 	GetU16(const U8 pu8Buffer[], const U16 u16Index, const EEndianness dir);
 void 	SetU16(const U16 u16, U8 pu8Buffer[], const U16 u16Index, const EEndianness dir);

 S16 	GetS16(const U8 pu8Buffer[], const U16 u16Index, const EEndianness dir);
 void 	SetS16(const S16 s16, U8 pu8Buffer[], const U16 u16Index, const EEndianness dir);

 U32 	GetU32(const U8 pu8Buffer[], const U16 u16Index, const EEndianness dir);
 void 	SetU32(const U32 u32, U8 pu8Buffer[], const U16 u16Index, const EEndianness dir);

 S32 	GetS32(const U8 pu8Buffer[], const U16 u16Index, const EEndianness dir);
 void 	SetS32(const S32 s32, U8 pu8Buffer[], const U16 u16Index, const EEndianness dir);

 U64 	GetU64(const U8 pu8Buffer[], const U16 u16Index, const EEndianness dir);
 void 	SetU64(const U64 u64, U8 pu8Buffer[], const U16 u16Index, const EEndianness dir);

 S64 	GetS64(const U8 pu8Buffer[], const U16 u16Index, const EEndianness dir);
 void 	SetS64(const S64 s64, U8 pu8Buffer[], const U16 u16Index, const EEndianness dir);

 FLT32 	GetFLT32(const U8 pu8Buffer[], const U16 u16Index, const EEndianness dir);
 void 	SetFLT32(const FLT32 f32, U8 pu8Buffer[], const U16 u16Index, const EEndianness dir);

 const U8* 	GetU8Stream(const U8 pu8Buffer[], const U16 u16Index);
 void 	SetU8Stream(const U8 pu8Src[], const U16 u16Len, U8 pu8Dest[], const U16 u16Index);

 const CHAR* 	GetString(const U8 pu8Buffer[], const U16 u16Index);
 void 	SetString(const CHAR pcSrc[], const U16 u16Len, U8 pu8Dest[], const U16 u16Index);




#endif /* SRC_TOOLBOX_ENDIANESSCONERTER_H_ */
