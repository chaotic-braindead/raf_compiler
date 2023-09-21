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
        case TOKEN_ID        : return "TOKEN_ID";
        case TOKEN_INT       : return "TOKEN_INT";
        case TOKEN_LPAREN    : return "TOKEN_LPAREN";
        case TOKEN_RPAREN    : return "TOKEN_RPAREN";
        case TOKEN_LCBRACE   : return "TOKEN_LCBRACE";
        case TOKEN_RCBRACE   : return "TOKEN_RCBRACE";
        case TOKEN_LBRACE    : return "TOKEN_LBRACE";
        case TOKEN_RBRACE    : return "TOKEN_RBRACE";
        case TOKEN_COLON     : return "TOKEN_COLON";
        case TOKEN_SEMICOLON : return "TOKEN_SEMICOLON";
        case TOKEN_SQUOTE    : return "TOKEN_SQUOTE";
        case TOKEN_DQUOTE    : return "TOKEN_DQUOTE";
        case TOKEN_PLUS      : return "TOKEN_PLUS";
        case TOKEN_MINUS     : return "TOKEN_MINUS";
        case TOKEN_ASTERISK  : return "TOKEN_ASTERISK";
        case TOKEN_FSLASH    : return "TOKEN_FSLASH";
        case TOKEN_BSLASH    : return "TOKEN_BSLASH";
        case TOKEN_PERCENT   : return "TOKEN_PERCENT";
        case TOKEN_EQUALS    : return "TOKEN_EQUALS";
        case TOKEN_COMMA     : return "TOKEN_COMMA";
        case TOKEN_LBRACKET  : return "TOKEN_LBRACKET";
        case TOKEN_RBRACKET  : return "TOKEN_RBRACKET";
        case TOKEN_ARROW     : return "TOKEN_ARROW";
        case TOKEN_COMMENT   : return "TOKEN_COMMENT";
        case TOKEN_EOF       : return "TOKEN_EOF";
    }
    return "TOKEN_UNPROCESSED";
}
