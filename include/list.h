#include <stddef.h>
#ifndef RAF_LIST_H
#define RAF_LIST_H

// TODO: figure out how this is all going to work lmao
typedef struct _LIST_T {
    void **items;
    size_t size;
    size_t itemSize;
} list_t;

list_t* listInit(size_t itemSize);
void listPush(list_t *list, void *item);
#endif