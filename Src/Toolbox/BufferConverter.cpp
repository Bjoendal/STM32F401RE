/*
 * EndianessConverter.cpp
 *
 *  Created on: 27.04.2020
 *      Author: Lukas
 */

#include <BufferConverter.h>

BOOL GetBOOL(const U8 pu8Buffer[], const U16 u16Index)
{
	return *reinterpret_cast<const BOOL*>(&	pu8Buffer[u16Index]	);
}

void SetBOOL(const BOOL b, U8 pu8Buffer[], const U16 u16Index)
{
	pu8Buffer[u16Index] = *reinterpret_cast<const U8*>(&b);
}

U8 GetU8(const U8 pu8Buffer[], const U16 u16Index)
{
	return pu8Buffer[u16Index];
}

void SetU8(const U8 u8, U8 pu8Buffer[], const U16 u16Index)
{
	pu8Buffer[u16Index] = u8;
}

S8 GetS8(const U8 pu8Buffer[], U16 u16Index)
{
	return *reinterpret_cast<const S8*>(&pu8Buffer[u16Index]);
}

void SetS8(const S8 s8, U8 pu8Buffer[], const U16 u16Index)
{
	pu8Buffer[u16Index] = *reinterpret_cast<const U8*>(&s8);
}

CHAR GetCHAR(const U8 pu8Buffer[], const U16 u16Index)
{
	return *reinterpret_cast<const CHAR*>(&pu8Buffer[u16Index]);
}

void SetCHAR(const CHAR c, U8 pu8Buffer[], const U16 u16Index)
{
	pu8Buffer[u16Index] = *static_cast<const CHAR*>(&c);
}

U16 GetU16(const U8 pu8Buffer[], const U16 u16Index, const EEndianness dir)
{
	    union
	    {
	        U8  ub[2];
	        U16 w;
	    }val;

	    if( ENDIAN_BIG == dir )
	    {
	    	val.ub[1] = GetU8(pu8Buffer, u16Index);
	    	val.ub[0] = GetU8(pu8Buffer, u16Index + 1U);
	    }else
	    {
	    	val.ub[0] = GetU8(pu8Buffer, u16Index);
	    	val.ub[1] = GetU8(pu8Buffer, u16Index + 1U);
	    }

		return val.w;
}

void SetU16(const U16 u16, U8 pu8Buffer[], const U16 u16Index, const EEndianness dir)
{
	    union
	    {
	        U8  ub[2];
	        U16 w;
	    }val;

	    val.w = u16;
	    if( ENDIAN_BIG == dir )
	    {
	    	SetU8(val.ub[1], pu8Buffer, u16Index);
	    	SetU8(val.ub[0], pu8Buffer, u16Index + 1U);
	    }else
	    {
	    	SetU8(val.ub[0], pu8Buffer, u16Index);
	    	SetU8(val.ub[1], pu8Buffer, u16Index + 1U);
	    }
}

S16 GetS16(const U8 pu8Buffer[], const U16 u16Index, const EEndianness dir)
{
    union
    {
        U8  ub[2];
        S16 w;
    }val;

    if( ENDIAN_BIG == dir )
    {
    	val.ub[1] = GetU8(pu8Buffer, u16Index);
    	val.ub[0] = GetU8(pu8Buffer, u16Index + 1U);
    }else
    {
    	val.ub[0] = GetU8(pu8Buffer, u16Index);
    	val.ub[1] = GetU8(pu8Buffer, u16Index + 1U);
    }

    return val.w;
}

void SetS16(const S16 s16, U8 pu8Buffer[], const U16 u16Index,	const EEndianness dir)
{
	 union
	    {
	        U8  ub[2];
	        S16 w;
	    }val;

	    val.w = s16;

	    if( ENDIAN_BIG == dir )
	    {
	    	SetU8(val.ub[1], pu8Buffer, u16Index);
	    	SetU8(val.ub[0], pu8Buffer, u16Index + 1U);
	    }else
	    {
	    	SetU8(val.ub[0], pu8Buffer, u16Index);
	    	SetU8(val.ub[1], pu8Buffer, u16Index + 1U);
	    }
}

U32 GetU32(const U8 pu8Buffer[], const U16 u16Index, const EEndianness dir)
{
	  union
	    {
	        U8  ub[4];
	        U32 dw;
	    }val;


	    if( ENDIAN_BIG == dir )
	    {
	    	val.ub[3] = GetU8(pu8Buffer, u16Index);
	    	val.ub[2] = GetU8(pu8Buffer, u16Index + 1U);
	    	val.ub[1] = GetU8(pu8Buffer, u16Index + 2U);
	    	val.ub[0] = GetU8(pu8Buffer, u16Index + 3U);
	    }else
	    {
	        val.ub[0] = GetU8(pu8Buffer, u16Index);
	        val.ub[1] = GetU8(pu8Buffer, u16Index + 1U);
	        val.ub[2] = GetU8(pu8Buffer, u16Index + 2U);
	        val.ub[3] = GetU8(pu8Buffer, u16Index + 3U);
	    }

	    return val.dw;
}

void SetU32(const U32 u32, U8 pu8Buffer[], const U16 u16Index, const EEndianness dir)
{
	  union
	    {
	        U8  ub[4];
	        U32 dw;
	    }val;

	    val.dw = u32;
	    if( ENDIAN_BIG == dir )
	    {
	    	SetU8(val.ub[3], pu8Buffer, u16Index);
	    	SetU8(val.ub[2], pu8Buffer, u16Index + 1U);
	    	SetU8(val.ub[1], pu8Buffer, u16Index + 2U);
	    	SetU8(val.ub[0], pu8Buffer, u16Index + 3U);
	    }else
	    {
	    	SetU8(val.ub[0], pu8Buffer, u16Index);
	    	SetU8(val.ub[1], pu8Buffer, u16Index + 1U);
	    	SetU8(val.ub[2], pu8Buffer, u16Index + 2U);
	    	SetU8(val.ub[3], pu8Buffer, u16Index + 3U);
	    }
}

S32 GetS32(const U8 pu8Buffer[], const U16 u16Index, const EEndianness dir)
{
	 union
	    {
	        S32 s32;
	        U32 u32;
	    }val;

		val.u32 = GetU32(pu8Buffer, u16Index, dir);
		return val.s32;
}

void SetS32(const S32 s32, U8 pu8Buffer[], const U16 u16Index,	const EEndianness dir)
{
	  union
	    {
	        S32 s;
	        U32 u;
	    }val;

		val.s = s32;

		SetU32(val.u, pu8Buffer, u16Index, dir);
}

U64 GetU64(const U8 pu8Buffer[], const U16 u16Index, const EEndianness dir)
{

	    union
	    {
	        U8  ub[4];
	        U64 u64;
	    }val;


	    if( ENDIAN_BIG == dir )
	    {
	    	val.ub[7] = GetU8(pu8Buffer, u16Index);
	    	val.ub[6] = GetU8(pu8Buffer, u16Index + 1U);
	    	val.ub[5] = GetU8(pu8Buffer, u16Index + 2U);
	    	val.ub[4] = GetU8(pu8Buffer, u16Index + 3U);
	    	val.ub[3] = GetU8(pu8Buffer, u16Index + 4U);
	    	val.ub[2] = GetU8(pu8Buffer, u16Index + 5U);
	    	val.ub[1] = GetU8(pu8Buffer, u16Index + 6U);
	    	val.ub[0] = GetU8(pu8Buffer, u16Index + 7U);
	    }else
	    {
	        val.ub[0] = GetU8(pu8Buffer, u16Index);
	        val.ub[1] = GetU8(pu8Buffer, u16Index + 1U);
	        val.ub[2] = GetU8(pu8Buffer, u16Index + 2U);
	        val.ub[3] = GetU8(pu8Buffer, u16Index + 3U);
	        val.ub[4] = GetU8(pu8Buffer, u16Index + 4U);
	        val.ub[5] = GetU8(pu8Buffer, u16Index + 5U);
	        val.ub[6] = GetU8(pu8Buffer, u16Index + 6U);
	        val.ub[7] = GetU8(pu8Buffer, u16Index + 7U);
	    }

	    return val.u64;
}

void SetU64(const U64 u64, U8 pu8Buffer[], const U16 u16Index, const EEndianness dir)
{
	   union
	    {
	        U8  ub[8];
	        U64 u64;
	    }val;

	    val.u64 = u64;

	    if( ENDIAN_BIG == dir )
	    {
	    	SetU8(val.ub[7], pu8Buffer, u16Index);
	    	SetU8(val.ub[6], pu8Buffer, u16Index + 1U);
	    	SetU8(val.ub[5], pu8Buffer, u16Index + 2U);
	    	SetU8(val.ub[4], pu8Buffer, u16Index + 3U);
	    	SetU8(val.ub[3], pu8Buffer, u16Index + 4U);
	    	SetU8(val.ub[2], pu8Buffer, u16Index + 5U);
	    	SetU8(val.ub[1], pu8Buffer, u16Index + 6U);
	    	SetU8(val.ub[0], pu8Buffer, u16Index + 7U);
	    }else
	    {
	    	SetU8(val.ub[0], pu8Buffer, u16Index);
	    	SetU8(val.ub[1], pu8Buffer, u16Index + 1U);
	    	SetU8(val.ub[2], pu8Buffer, u16Index + 2U);
	    	SetU8(val.ub[3], pu8Buffer, u16Index + 3U);
	    	SetU8(val.ub[4], pu8Buffer, u16Index + 4U);
	    	SetU8(val.ub[5], pu8Buffer, u16Index + 5U);
	    	SetU8(val.ub[6], pu8Buffer, u16Index + 6U);
	    	SetU8(val.ub[7], pu8Buffer, u16Index + 7U);
	    }
}

S64 GetS64(const U8 pu8Buffer[], const U16 u16Index, const EEndianness dir)
{
	 union
	    {
	        S64 s;
	        U64 u;
	    }val;
	    //lint +esym(1960,9-5-1)

		val.u = GetU64(pu8Buffer, u16Index, dir);
		return val.s;
}

void SetS64(const S64 s64, U8 pu8Buffer[], const U16 u16Index,	const EEndianness dir)
{
	  union
	    {
	        S64 s;
	        U64 u;
	    }val;

		val.s = s64;


		SetU64(val.u, pu8Buffer, u16Index, dir);
}

FLT32 GetFLT32(const U8 pu8Buffer[], const U16 u16Index, const EEndianness dir)
{
	union
	    {
	        FLT32 f32;
	        U32 u32;
	    }val;

		val.u32 = GetU32(pu8Buffer, u16Index, dir);

		return val.f32;
}

void SetFLT32(const FLT32 f32, U8 pu8Buffer[], const U16 u16Index,	const EEndianness dir)
{
	 union
	    {
	        FLT32 f;
	        U32 u;
	    }val;

		val.f = f32;

		SetU32(val.u, pu8Buffer, u16Index, dir);
}

const U8* GetU8Stream(const U8 pu8Buffer[], const U16 u16Index)
{
	return &pu8Buffer[u16Index];
}

void SetU8Stream(const U8 pu8Src[], const U16 u16Len, U8 pu8Dest[],	const U16 u16Index)
{
	U16 u16Pos = 0U;

	if(4U < u16Len)
	{
		while( (u16Len - u16Pos) > 4U )
		{
			pu8Dest[u16Index + u16Pos] = pu8Src[u16Pos];
			u16Pos++;
			pu8Dest[u16Index + u16Pos] = pu8Src[u16Pos];
			u16Pos++;
			pu8Dest[u16Index + u16Pos] = pu8Src[u16Pos];
			u16Pos++;
			pu8Dest[u16Index + u16Pos] = pu8Src[u16Pos];
			u16Pos++;
		}
	}


	while( u16Pos < u16Len )
	{
		pu8Dest[u16Index + u16Pos] = pu8Src[u16Pos];
		u16Pos++;
	}
}

const CHAR* GetString(const U8 pu8Buffer[], const U16 u16Index)
{
	return reinterpret_cast<const CHAR*>( &pu8Buffer[u16Index] );
}

void SetString(const CHAR pcSrc[], const U16 u16Len, U8 pu8Dest[],	const U16 u16Index)
{
	SetU8Stream(reinterpret_cast<const U8*const>(pcSrc), u16Len, pu8Dest, u16Index);
}
