#include "list.h"
#ifndef RAF_STREE_H
#define RAF_STREE_H

typedef struct _STREE_T {
    list_t children;
    enum {
        STREE_COMPOUND,
        STREE_FUNCTION,
        STREE_ID,
        STREE_DECLARATION,
        STREE_INIT,
    }type;
} stree_t;

// TODO: initialize an abstract syntax tree
stree_t* streeInit();
#endif