#include "hash_map.h"
#include "hash_map(str,int).h"


#include "upc_assert_message.h"


int main(int argc, char* argv[])
{
    //  再初 hash_map
    struct hash_trait trait = {0};
    struct hash_map h = {0};
    hash_map_init(&h, hash_map_str_int_trait_init(&trait), 97);

    struct hash_node* repl = hash_map_put(&h, (struct hash_node*)hash_map_str_int_entry_new("a", 1));
    ASSERT_MESSAGE((NULL == repl), "返回值为NULL");

    struct hash_map_str_key str_key;
    hash_map_str_key_init(&str_key, "a");
    struct hash_map_str_int_entry* get_item = (struct hash_map_str_int_entry*)hash_map_get(&h, &str_key);
    ASSERT_MESSAGE((NULL != get_item), "返回值不能为NULL");
    ASSERT_MESSAGE((1 == get_item->val), "返回的 node 必须与添加的时候一致");
    ASSERT_MESSAGE((1 == hash_map_size(&h)), "个数必须正确");

    return 0;
}
