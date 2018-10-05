#include "hash_map.h"

#include "hash_map(str,int).h"



int main(int argc, char* argv[])
{
    //  ÔÙ³õ hash_map
    struct hash_trait trait = {0};
    struct hash_map h = {0};
    hash_map_init(&h, hash_map_str_int_trait_init(&trait), 97);

    hash_map_put(&h, (struct hash_node*)hash_map_str_int_entry_new("a", 1));

    //hash_map_get()
    return 0;
}
