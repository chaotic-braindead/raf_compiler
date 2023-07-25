#include "include/token.h"
#include <stdlib.h>
#include <stdio.h>

token_t* tokenInit(char *buf, token_type type){
    token_t *newToken = calloc(1, sizeof(struct _TOKEN_T));
    newToken->buf = buf;
    newToken->type = type;
    return newToken;
}

void tokenTypeToWords(token_type type){
    switch(type){
        case 0 : printf("TOKEN_ID"); break;
        case 1 : printf("TOKEN_INT"); break;
        case 2 : printf("TOKEN_LPAREN"); break;
        case 3 : printf("TOKEN_RPAREN"); break;
        case 4 : printf("TOKEN_LCBRACE"); break;
        case 5 : printf("TOKEN_RCBRACE"); break;
        case 6 : printf("TOKEN_LBRACE"); break;
        case 7 : printf("TOKEN_RBRACE"); break;
        case 8 : printf("TOKEN_COLON"); break;
        case 9 : printf("TOKEN_SEMICOLON"); break;
        case 10 : printf("TOKEN_SQOUTE"); break;
        case 11 : printf("TOKEN_DQUOTE"); break;
        case 12 : printf("TOKEN_PLUS"); break;
        case 13 : printf("TOKEN_MINUS"); break;
        case 14 : printf("TOKEN_ASTERISK"); break;
        case 15 : printf("TOKEN_FSLASH"); break;
        case 16 : printf("TOKEN_BSLASH"); break;
        case 17 : printf("TOKEN_PERCENT"); break;
        case 18 : printf("TOKEN_EQUALS"); break;
        case 19 : printf("TOKEN_EOF"); break;
        case 20 : printf("TOKEN_UNPROCESSED"); break;
    }
}
