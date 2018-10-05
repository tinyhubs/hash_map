#ifndef _upc_assert_message_H_
#define _upc_assert_message_H_


#include <assert.h>


//  定义了一个支持带消息字段的断言
#ifndef ASSERT_MESSAGE
#define ASSERT_MESSAGE(expr,message)   assert(expr)
#endif//ASSERT_MESSAGE


#endif//_upc_assert_message_H_


