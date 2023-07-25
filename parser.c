#include "include/parser.h"
#include "include/lexer.h"
#include "include/token.h"
#include <stdlib.h>

parser_t* parserInit(char *src){
    parser_t *newParser = malloc(sizeof(struct _PARSER_T));
    lexer_t *newLexer = lexerInit(src);
    newParser->lexer = newLexer;
    return newParser;
}

int parserGetNewToken(parser_t *parser){
    if(!(parser->token)) return 0;
    parser->token = lexerProcess(parser->lexer); 
    return parser->token->type != TOKEN_EOF;
}