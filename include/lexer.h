#ifndef RAF_LEXER_H
#define RAF_LEXER_H
#include "include/token.h"

typedef struct _LEXER_T{
    char *src;
    size_t srcSize;
    unsigned int i;
    char c;
} lexer_t;

lexer_t* lexerInit(char *src);
void lexerNext(lexer_t *lexer);
token_t* lexerNextReturn(lexer_t *lexer, token_t *token);
void lexerProcessWhitespace(lexer_t *lexer);
token_t* lexerProcessID(lexer_t *lexer);
token_t* lexerProcessDigit(lexer_t *lexer);
token_t* lexerProcess(lexer_t *lexer);

#endif