#include "include/list.h"
#include <stdlib.h>

list_t* listInit(size_t itemSize){
    list_t *newList = malloc(sizeof(struct _LIST_T)); 
    newList->items = NULL;
    newList->size = 0;
    newList->itemSize = itemSize;
    return newList;
}

void listPush(list_t *list, void *item){
    if(!list->items)
        list->items = malloc(list->itemSize);
    else  
        list->items = realloc(list->items, list->itemSize + 1);
    
    list->items[list->size++] = item;
}