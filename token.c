#include "include/token.h"
#include <stdlib.h>
#include <stdio.h>

token_t* tokenInit(char *buf, token_type type){
    token_t *newToken = malloc(sizeof(struct _TOKEN_T));
    newToken->buf = buf;
    newToken->type = type;
    return newToken;
}


// there's definitely a better way to do this but I already put in too much effort on this lmao
char* tokenTypeToWords(token_type type){
    switch(type){
        case 0 : return "TOKEN_ID";
        case 1 : return "TOKEN_INT";
        case 2 : return "TOKEN_LPAREN";
        case 3 : return "TOKEN_RPAREN";
        case 4 : return "TOKEN_LCBRACE";
        case 5 : return "TOKEN_RCBRACE";
        case 6 : return "TOKEN_LBRACE";
        case 7 : return "TOKEN_RBRACE";
        case 8 : return "TOKEN_COLON";
        case 9 : return "TOKEN_SEMICOLON";
        case 10 : return "TOKEN_SQOUTE";
        case 11 : return "TOKEN_DQUOTE";
        case 12 : return "TOKEN_PLUS";
        case 13 : return "TOKEN_MINUS";
        case 14 : return "TOKEN_ASTERISK";
        case 15 : return "TOKEN_FSLASH";
        case 16 : return "TOKEN_BSLASH";
        case 17 : return "TOKEN_PERCENT";
        case 18 : return "TOKEN_EQUALS";
        case 19 : return "TOKEN_COMMA";
        case 20 : return "TOKEN_LBRACKET";
        case 21 : return "TOKEN_RBRACKET";
        case 22 : return "TOKEN_ARROW";
        case 23 : return "TOKEN_COMMENT";
        case 24 : return "TOKEN_EOF";
    }
    return "TOKEN_UNPROCESSED";
}
