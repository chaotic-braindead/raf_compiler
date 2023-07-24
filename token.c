#include "include/token.h"
#include <stdlib.h>

token_t* tokenInit(char *buf, token_type type){
    token_t *newToken = calloc(1, sizeof(struct _TOKEN_T));
    newToken->buf = buf;
    newToken->type = type;
    return newToken;
}