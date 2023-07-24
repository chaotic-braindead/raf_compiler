#ifndef RAF_TOKEN_H
#define RAF_TOKEN_H
#define token_type unsigned int

typedef struct _TOKEN_T{
    char *buf;
    enum{
        TOKEN_ID,
        TOKEN_INT,
        TOKEN_LPAREN,
        TOKEN_RPAREN,
        TOKEN_LCBRACE,
        TOKEN_RCBRACE,
        TOKEN_LBRACE,
        TOKEN_RBRACE,
        TOKEN_COLON,
        TOKEN_SEMICOLON,
        TOKEN_SQUOTE,
        TOKEN_DQUOTE,
        TOKEN_PLUS,
        TOKEN_MINUS,
        TOKEN_ASTERISK,
        TOKEN_FSLASH,
        TOKEN_BSLASH,
        TOKEN_PERCENT,        
        TOKEN_EQUALS,
        TOKEN_EOF,
        TOKEN_UNPROCESSED
    } type;
} token_t;

token_t* tokenInit(char *buf, token_type type);

#endif