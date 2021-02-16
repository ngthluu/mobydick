#ifndef __LEXER_H__
#define __LEXER_H__

typedef enum {
    BEGIN_PLACEHOLDER,

    ID,             // ID
    REAL_LIT,       // Real literals
    INT_LIT,        // Integer literals
    STR_LIT,        // String literals
    OP_AND,         // &&
    OP_OR,          // ||
    OP_NOT,         // !!
    OP_IS,          // ==
    OP_GRE,         // >=
    OP_LSE,         // <=
    OP_GR,          // >
    OP_LS,          // <
    OP_ADD,         // +
    OP_SUB,         // -
    OP_MUL,         // *
    OP_DIV,         // /
    OP_MOD,         // %
    OP_POW,         // ^
    OP_FAC,         // !
    OP_IF,          // ?
    CUR_BEG,        // (
    CUR_END,        // )
    BCE_BEG,        // {
    BCE_END,        // }
    COMMA,          // ,
    SEMICOLON,      // ;
    INFER,          // =>
    ASSIGN,         // =

    END_PLACEHOLDER
} token_id;

typedef struct {
    token_id id;
    char* src;
} token_t;

token_t* get_tokens_from(char* src);

#endif