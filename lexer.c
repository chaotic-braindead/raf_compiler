#include "include/lexer.h"
#include "include/token.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

lexer_t* lexerInit(char *src){
    lexer_t *newLexer = calloc(1, sizeof(struct _LEXER_T));
    newLexer->src = src;
    newLexer->srcSize = strlen(src);
    newLexer->i = 0;
    newLexer->c = newLexer->src[newLexer->i];
    return newLexer;
}

void lexerNext(lexer_t *lexer){
    if(lexer->i < lexer->srcSize && lexer->src[lexer->i] != '\0'){
        lexer->i++;
        lexer->c = lexer->src[lexer->i];
    }
}

token_t* lexerNextOnReturn(lexer_t *lexer, token_t *token){
    return token;
}

void lexerProcessWhitespace(lexer_t *lexer){ 
    while(lexer->c == ' ' || lexer->c == '\t' || lexer->c == '\n' || lexer->c == 32 || lexer->c == 13){
        lexerNext(lexer);
    }
}
token_t* lexerProcessID(lexer_t *lexer){
    char *buf = calloc(1, sizeof(char));
    while(isalpha(lexer->c)){
        buf = realloc(buf, (strlen(buf) + 2) * sizeof(char));
        char temp[2] = {lexer->c};
        strcat(buf, temp);
        lexerNext(lexer);
    }
    return tokenInit(buf, TOKEN_ID);
}
token_t* lexerProcessDigit(lexer_t *lexer){
    char *buf = calloc(1, sizeof(char));
    while(isdigit(lexer->c)){
        buf = realloc(buf, (strlen(buf) + 2) * sizeof(char));
        char temp[2] = {lexer->c};
        strcat(buf, temp);
        lexerNext(lexer);
    }
    return tokenInit(buf, TOKEN_INT);
}
token_t* lexerProcessOther(lexer_t *lexer, token_type type){
    char *buf = calloc(2, sizeof(char));
    buf[0] = lexer->c;
    buf[1] = '\0';

    lexerNext(lexer);
    return tokenInit(buf, type);
}
token_t* lexerProcess(lexer_t *lexer){
    while(lexer->c != '\0'){
        lexerProcessWhitespace(lexer);
        if(isalpha(lexer->c)){
            return lexerNextOnReturn(lexer, lexerProcessID(lexer));
        }
        if(isdigit(lexer->c)){
            return lexerNextOnReturn(lexer, lexerProcessDigit(lexer));
        }
        switch(lexer->c){
            case '(': return lexerProcessOther(lexer, TOKEN_LPAREN);
            case ')': return lexerProcessOther(lexer, TOKEN_RPAREN);
            case '{': return lexerProcessOther(lexer, TOKEN_LCBRACE);
            case '}': return lexerProcessOther(lexer, TOKEN_RCBRACE);
            case '[': return lexerProcessOther(lexer, TOKEN_LBRACE);
            case ']': return lexerProcessOther(lexer, TOKEN_RBRACE);
            case ':': return lexerProcessOther(lexer, TOKEN_COLON); 
            case ';': return lexerProcessOther(lexer, TOKEN_SEMICOLON);
            case '=': return lexerProcessOther(lexer, TOKEN_EQUALS);
            default: return lexerProcessOther(lexer, TOKEN_UNPROCESSED);
        }
    }
    return tokenInit(0, TOKEN_EOF);
}