#include <stdio.h>

#define HASHSIZE 12
#deinfe NULLKEY -32768
typedef struct
{
    int* elem;
    int  count;
}HashTable;

int InitHashTable(HashTable *H)
{
    H->count = HASHSIZE;
    H->elem = (int *)malloc(HASHSIZE * sizeof(int));
    if (!H->elem)
    {
        return -1;
    }
    for( i=0; i < HASHSIZE; i++)
    {
        H->elem[i] = NULLKEY;
    }
    return 0;
}

int Hash(int key)
{
    return key % HASHSIZE;
}

void InsertHashTable(HashTable* H, int key)
{
    int addr;

    addr = Hash(key);

    while( H->elem[addr] != NULLKEY)
    {
        addr = (addr + 1) % HASHSIZE;
    }
    H->elem[addr] = key;
}

void SearchHashTable(HashTable *H, int key, int* addr)
{
    *addr = Hash(key);
    while(H.elem[*addr] != key)
    {
        *addr = (*addr + 1) % HASHSIZE;
        if (H.elem[*addr] == NULLKEY || *addr == Hash(key))
        {
            return -1;
        }
    }
    return 0;
}

int main(void)
{

}
