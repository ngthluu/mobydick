#ifndef __LEXER_H__
#define __LEXER_H__

typedef enum t_token {
    ID,             // ID
    INT_LIT,        // Integer literals
    REAL_LIT,       // Real literals
    STR_LIT,        // String literals
    OP_AND,         // &&
    OP_OR,          // ||
    OP_NOT,         // !!
    OP_IS,          // ==
    OP_GR,          // >
    OP_LS,          // <
    OP_GRE,         // >=
    OP_LSE,         // <=
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
    ASSIGN,         // =
    INFER           // =>
} t_token;



t_token* get_tokens_from(char* src);

#endif