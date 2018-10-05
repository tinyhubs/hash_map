#ifndef _upc_types_H_
#define _upc_types_H_


#include "upc_static_assert.h"


typedef unsigned char       uint8;
typedef          char       int8;

typedef unsigned short      uint16;
typedef          short      int16;

typedef unsigned short      uint16;
typedef          short      int16;

typedef unsigned int        uint32;
typedef          int        int32;

typedef unsigned long long  uint64;
typedef long long           int64;


//	通过静态断言检查使用者的编译期对于这些类型的支持是否满足要求
STATIC_ASSERT((sizeof(uint8)  == 1), "");
STATIC_ASSERT((sizeof(int8)   == 1), "");
STATIC_ASSERT((sizeof(uint16) == 2), "");
STATIC_ASSERT((sizeof(int16)  == 2), "");
STATIC_ASSERT((sizeof(uint32) == 4), "");
STATIC_ASSERT((sizeof(int32)  == 4), "");
STATIC_ASSERT((sizeof(uint64) == 8), "");
STATIC_ASSERT((sizeof(int64)  == 8), "");



#endif//_upc_types_H_


