#include "include/lexer.h"
#include "include/token.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

lexer_t* lexerInit(char *src){
    lexer_t *newLexer = malloc(sizeof(struct _LEXER_T));
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

char lexerPeek(lexer_t *lexer){
    return lexer->i < lexer->srcSize ? lexer->src[(lexer->i)+1] : '\0';
}

void lexerProcessWhitespace(lexer_t *lexer){ 
    while(lexer->c == ' ' || lexer->c == '\t' || lexer->c == '\n' || lexer->c == 32 || lexer->c == 13){
        lexerNext(lexer);
    }
}
token_t* lexerProcessID(lexer_t *lexer){
    char *buf = calloc(1, sizeof(char));
    while(isalpha(lexer->c) || lexer->c == '_'){
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
        strcat(buf, (char[]){lexer->c, 0});
        lexerNext(lexer);
    }
    return tokenInit(buf, TOKEN_INT);
}
token_t* lexerProcessComment(lexer_t *lexer){
    char *buf = calloc(1, sizeof(char));
    char c, before;

    // multi-line comment (this is kinda janky. i could've probably used a stack or something but i'm too lazy right now)
    if(lexerPeek(lexer) == '#'){
        int check = 0;
        while(1){
            if(c) before = c;
            c = lexerPeek(lexer);
            if(before == '#') check++;
            else check = 0;
            buf = realloc(buf, strlen(buf) + 2);
            strcat(buf, (char[]){lexer->c, 0});
            lexerNext(lexer);
            if(check == 2) break;
            if(lexer->i == lexer->srcSize) break;
        }
        return tokenInit(buf, TOKEN_COMMENT);
    }
    
    // single line comment
    while(c = lexerPeek(lexer)){
        if(c == '\0' || c == '\n') break;
        buf = realloc(buf, strlen(buf) + 2);
        strcat(buf, (char[]){lexer->c, 0});
        lexerNext(lexer);
    }
    return tokenInit(buf, TOKEN_COMMENT);
}

token_t* lexerProcessArrow(lexer_t *lexer){
    char *buf = calloc(3, sizeof(char));
    buf[0] = '=';
    buf[1] = '>';
    buf[2] = '\0';
    lexerNext(lexer);
    lexerNext(lexer);
    return tokenInit(buf, TOKEN_ARROW);
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
            case '\'': return lexerProcessOther(lexer, TOKEN_SQUOTE);
            case '\"': return lexerProcessOther(lexer, TOKEN_DQUOTE);
            case '+': return lexerProcessOther(lexer, TOKEN_PLUS);
            case '-': return lexerProcessOther(lexer, TOKEN_MINUS);
            case '*': return lexerProcessOther(lexer, TOKEN_ASTERISK);
            case '/': return lexerProcessOther(lexer, TOKEN_FSLASH);
            case '\\': return lexerProcessOther(lexer, TOKEN_BSLASH);
            case '%': return lexerProcessOther(lexer, TOKEN_PERCENT);
            case '=': return lexerPeek(lexer) == '>' ? lexerProcessArrow(lexer) : lexerProcessOther(lexer, TOKEN_EQUALS); 
            case ',' : return lexerProcessOther(lexer, TOKEN_COMMA);
            case '<' : return lexerProcessOther(lexer, TOKEN_LBRACKET);
            case '>' : return lexerProcessOther(lexer, TOKEN_RBRACKET);
            case '#' : return lexerProcessComment(lexer);
            default: return lexerProcessOther(lexer, TOKEN_UNPROCESSED);
        }
    }
    return tokenInit(0, TOKEN_EOF);
}