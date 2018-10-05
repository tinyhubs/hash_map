#ifndef __hash_func_int_H_
#define __hash_func_int_H_


#include "upc_types.h"
#include "upc_static_assert.h"


/* 2^31 + 2^29 - 2^25 + 2^22 - 2^19 - 2^16 + 1 */
#define GOLDEN_RATIO_PRIME_32 0x9e370001UL
/*  2^63 + 2^61 - 2^57 + 2^54 - 2^51 - 2^18 + 1 */
#define GOLDEN_RATIO_PRIME_64 0x9e37fffffffc0001UL



static inline  uint64 hash_64(uint64 val, unsigned int bits)
{
    uint64 hash = val;

    /*  Sigh, gcc can't optimise this alone like it does for 32 bits. */
    uint64 n = hash;
    n <<= 18;
    hash -= n;
    n <<= 33;
    hash -= n;
    n <<= 3;
    hash += n;
    n <<= 3;
    hash -= n;
    n <<= 4;
    hash += n;
    n <<= 2;
    hash += n;

    /* High bits are more random, so use them. */
    return hash >> (64 - bits);
}

static inline  uint32 hash_32(uint32 val, unsigned int bits)
{
    /* On some cpus multiply is faster, on others gcc will do shifts */
    uint32 hash = val * GOLDEN_RATIO_PRIME_32;

    /* High bits are more random, so use them. */
    return hash >> (32 - bits);
}


#if   (sizeof(long) * 8) == 32
#define hash_long(val, bits) hash_32(val, bits)
#elif (sizeof(long) * 8) == 64
#define hash_long(val, bits) hash_64(val, bits)
#else
#error Wordsize not 32 or 64
#endif


#define hash_ptr(ptr, bits) hash_long((unsigned long)ptr, bits);



STATIC_ASSERT((sizeof(long) == sizeof(void*)), "字符串长度必须等于 long 类型的长度");



#endif//__hash_func_int_H_
