#include "include/raf.h"
#include "include/parser.h"
#include <stdio.h>

int rafCompile(char *src){
    if(!src) return EXIT_FAILURE;

    parser_t *parser = parserInit(src);
    token_t *tToken;

    while(parserGetNewToken(parser)){
        tToken = parser->token;
        if(tToken->type == TOKEN_COMMENT) continue;
        if(tToken->type == TOKEN_UNPROCESSED) {
            printf("[Lexer]: ERROR - Invalid character %s found in program.", tToken->buf);
            exit(EXIT_FAILURE);
        }

        printf("TOKEN = %s\t| TYPE = %s\n", tToken->buf, tokenTypeToWords(tToken->type));
        free(tToken->buf);
        free(parser->token);
    }
    if(parser->lexer) free(parser->lexer);
    if(parser->token) {free(parser->token->buf); free(parser->token);}
    if(parser) free(parser);   

    return EXIT_SUCCESS;
}
