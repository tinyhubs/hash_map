#ifndef _upc_static_assert_H_
#define _upc_static_assert_H_


#include <assert.h>


//  定义了一个编译期断言
#ifndef STATIC_ASSERT
#ifdef  __cplusplus
#define STATIC_ASSERT(const_expr,message)   static_assert(const_expr,message)
#else
#define STATIC_ASSERT(const_expr,message)   static_assert(const_expr,message)
#endif//
#endif//



#endif//_upc_static_assert_H_


