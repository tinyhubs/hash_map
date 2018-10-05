#include "hash_map(str,int).h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "upc_assert_message.h"


static struct hash_key hash_map_str_int_entry_key(struct hash_trait* trait, struct hash_node* node)
{
    ASSERT_MESSAGE((NULL != trait), "由外部保证 trait 参数的有效性");
    ASSERT_MESSAGE((NULL != node), "由外部保证 node 参数的有效性");

    struct hash_map_str_int_entry* entry = (struct hash_map_str_int_entry*)node;
    struct hash_key key = {&(entry->key.key)};
    return key;
}




static uint32          hash_map_str_int_entry_hash(struct hash_trait* trait, struct hash_key   key)
{
    ASSERT_MESSAGE((NULL != trait), "由外部保证 trait 参数的有效性");
    ASSERT_MESSAGE((NULL != key.data), "由外部保证 key.data 有效性");
    struct hash_map_str_int_entry* entry = (struct hash_map_str_int_entry*)(key.data);
    return entry->key.hash;
}




static int32           hash_map_str_int_entry_equal(struct hash_trait* trait, struct hash_key   key1, struct hash_key   key2)
{
    struct hash_map_str_int_entry* entry1 = (struct hash_map_str_int_entry*)(key1.data);
    struct hash_map_str_int_entry* entry2 = (struct hash_map_str_int_entry*)(key2.data);
    return (entry1->key.hash == entry2->key.hash) && (0 == strcmp(entry1->key.key, entry2->key.key));
}




void            hash_map_str_int_entry_del(struct hash_map_str_int_entry* entry)
{
    if (NULL == entry)
    {
        return;
    }

    if (NULL != entry->key.key)
    {
        free(entry->key.key);
    }

    free(entry);
}




hash_map_str_int_entry* hash_map_str_int_entry_new(char* key, int val)
{
    struct hash_map_str_int_entry* entry = (struct hash_map_str_int_entry*)malloc(sizeof(struct hash_map_str_int_entry));
    if (NULL == entry)
    {
        return NULL;
    }

    entry->node.next = NULL;
    entry->node.prev = NULL;

    size_t key_len = strlen(key) + 1;
    entry->key.key = (char*)malloc(key_len);
    if (NULL == entry->key.key)
    {
        goto    fail;
    }
    memcpy(entry->key.key, key, key_len);
    entry->key.hash = 

    entry->val = val;

    return entry;

fail:
    hash_map_str_int_entry_del(entry);
    return NULL;
}




struct hash_trait*  hash_map_str_int_trait_init(struct hash_trait* trait)
{
    trait->key   = hash_map_str_int_entry_key;
    trait->hash  = hash_map_str_int_entry_hash;
    trait->equal = hash_map_str_int_entry_equal;
    return trait;
}




struct hash_map_str_key*    hash_map_str_key_init(struct hash_map_str_key* key, char* str)
{
    key->hash()
}



