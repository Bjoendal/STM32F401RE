
#ifndef Types_H
#define Types_H

// Erforderlich für die Verwendung der XModem-Library aus Plattform 3
// Info: In P3 wird hier die stddef.h includiert => Lint-Meldungen
typedef unsigned  int         size_t;

typedef unsigned  char        BOOL;

typedef char                  CHAR;

typedef signed    char        S8;
typedef unsigned  char        U8;

typedef signed    short       S16;
typedef unsigned  short       U16;

typedef signed    long        S32;
typedef unsigned  long        U32;

typedef signed    long long   S64;
typedef unsigned  long long   U64;

typedef float                 FLT32;
typedef float                 DBL64;

#ifdef __cplusplus
static const S8  S8_MIN     = static_cast<S8>(-128);
#else
static const S8  S8_MIN     = (S8)-128;
#endif
static const S8  S8_MAX     = 127;
static const U8  U8_MAX     = 255U;


#ifdef __cplusplus
static const S16 S16_MIN    = static_cast<S16>(-32768);
#else
static const S16 S16_MIN    = (S16)-32768;
#endif
static const S16 S16_MAX    = 32767;
static const U16 U16_MAX    = 65535U;


#ifdef __cplusplus
static const S32 S32_MIN    = static_cast<S32>(-2147483648);
#else
static const S32 S32_MIN    = (S32)-2147483648; //lint !e501
#endif
static const S32 S32_MAX    = 2147483647L;
static const U32 U32_MAX    = 4294967295U;

static const S64 S64_MIN    = (-9223372036854775807LL -1);
static const S64 S64_MAX    = 9223372036854775807LL;
static const U64 U64_MAX    = 18446744073709551615ULL;

static const FLT32 FLT32_MIN = 1.18e-38F;
static const FLT32 FLT32_MAX = 3.39e38F;

static const DBL64 DBL64_MIN = 1.18e-38F;
static const DBL64 DBL64_MAX = 3.39e38F;

#ifdef __cplusplus
   #define NULL 0
   #define EXTERN_C extern "C"
   #define EXTERN_C_BEGIN extern "C" {
   #define EXTERN_C_END }
#else /* __cplusplus */
   #define NULL ((void *)0)
   #define EXTERN_C
   #define EXTERN_C_BEGIN
   #define EXTERN_C_END
#endif  /* __cplusplus */

#define TRUE  (1U)
#define FALSE (0U)

#endif

