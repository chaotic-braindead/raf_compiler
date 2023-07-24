#include "include/token.h"
#include <stdlib.h>

token_t* tokenInit(char *buf, unsigned int type){
    token_t *newToken = calloc(1, sizeof(struct _TOKEN_T));
    newToken->buf = buf;
    newToken->type = type;
    return newToken;
}