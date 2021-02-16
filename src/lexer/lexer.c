#include <regex.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "lexer.h"

// Functions defination
char* get_first_match(char* str, char* pattern);
char* get_regex_of_token_id(token_id id);
token_t* get_tokens_from(char* src);


// Functions implementation
char* get_first_match(char* str, char* pattern) {

    regex_t regex;
    int msg;
    
    // Init pattern
    char n_pattern[strlen(pattern) + 1]; 
    sprintf(n_pattern, "^%s", pattern);

    // Compile regex
    msg = regcomp(&regex, n_pattern, REG_EXTENDED);
    if (msg) {
        return NULL;
    }

    // Get matched
    int nmatch = 1;
    regmatch_t pmatch[nmatch];
    msg = regexec(&regex, str, nmatch, pmatch, 0);
    if (msg) {
        return NULL;
    }
    // Free regex
    regfree(&regex);

    // Return result
    char* result = (char*) malloc((pmatch[0].rm_eo - pmatch[0].rm_so) * sizeof(char));
    sprintf(result, "%.*s", pmatch[0].rm_eo - pmatch[0].rm_so, str + pmatch[0].rm_so);
    return result;
}

char* get_regex_of_token_id(token_id id) {
    switch (id) {
        case ID: return "[a-zA-Z][a-zA-Z0-9_]*";
        case INT_LIT: return "[0-9]+";
        case REAL_LIT: return "[0-9]+.[0-9]+";
        case STR_LIT: return "\"(^(\t\n\r\"))*\"";
        case OP_AND: return "&&";
        case OP_OR: return "||";
        case OP_NOT: return "!!";
        case OP_IS: return "==";
        case OP_GR: return ">";
        case OP_LS: return "<";
        case OP_GRE: return ">=";
        case OP_LSE: return "<=";
        case OP_ADD: return "+";
        case OP_SUB: return "-";
        case OP_MUL: return "*";
        case OP_DIV: return "/";
        case OP_MOD: return "%";
        case OP_POW: return "^";
        case OP_FAC: return "!";
        case OP_IF: return "?";
        case CUR_BEG: return "(";
        case CUR_END: return ")";
        case BCE_BEG: return "{";
        case BCE_END: return "}";
        case COMMA: return ",";
        case SEMICOLON: return ";";
        case ASSIGN: return "=";
        case INFER: return "=>";
        default: return NULL;
    }
}

token_t* get_tokens_from(char* src) {
    char* f_match = get_first_match("12abcdsdef123", "[a-z]+");
    printf("%s \n", f_match);
    free(f_match);
    return 0;
}