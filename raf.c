#include "include/raf.h"
#include "include/lexer.h"
#include "include/io.h"
#include "include/token.h"
#include <stdio.h>

void rafCompile(char *src){
    lexer_t *lexer = lexerInit(src);
    token_t *token;
    while((token = lexerProcess(lexer))->type != TOKEN_EOF){
        printf("TOKEN = %s\t| TYPE = ", token->buf);
        tokenTypeToWords(token->type);
        printf("\n");
        free(token);
    }
    
}
