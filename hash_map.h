#ifndef __hash_map_H_
#define __hash_map_H_


#include "upc_types.h"


struct hash_node
{
    struct hash_node*   next;
    struct hash_node*   prev;
};

struct hash_bucket
{
    struct hash_node*   first;
};

struct hash_key
{
    void*   data;
};


struct hash_map
{
    struct hash_trait*  trait;
    int                 buckets_cap;
    struct hash_bucket* buckets;
    int                 count;
};



struct hash_trait
{
    struct hash_key (*key   )(struct hash_trait* trait, struct hash_node* node);
    uint32          (*hash  )(struct hash_trait* trait, struct hash_key   key);
    int32           (*equal )(struct hash_trait* trait, struct hash_key   key1, struct hash_key   key2);
};


struct hash_map*    hash_map_init   (struct hash_map* h, struct hash_trait* trait, int buckets_size); 
void                hash_map_exit   (struct hash_map* h); 
struct hash_node*   hash_map_put    (struct hash_map* h, struct hash_node* n);
struct hash_node*   hash_map_get    (struct hash_map* h, struct hash_key key);
struct hash_node*   hash_map_pop    (struct hash_map* h, struct hash_key key);



#endif//__hash_map_H_
