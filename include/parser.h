#include "token.h"
#include "lexer.h"

#ifndef RAF_PARSER_H
#define RAF_PARSER_H

typedef struct _PARSER_T{
    lexer_t *lexer;
    token_t *token;
} parser_t;


parser_t* parserInit(char *src);
int parserGetNewToken(parser_t *parser);
void parserProcessCompound(parser_t *parser);
void parserProcessFuncDef(parser_t *parser);
void parserProcessVariable(parser_t *parser);
void parserProcessAssignment(parser_t *parser);
void parserProcessStatement(parser_t *parser);
void parserProcessNoOperation(parser_t *parser);

#endif