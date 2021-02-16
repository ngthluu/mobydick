#include <regex.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "lexer.h"

// Functions defination
char* get_first_match(char* str, char* pattern);
char* get_regex_of_token_id(token_id id);
void remove_spaces(char *s);
void remove_comments(char *s);
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
    regmatch_t pmatch[1];
    msg = regexec(&regex, str, 1, pmatch, 0);
    if (msg) {
        return NULL;
    }
    // Free regex
    regfree(&regex);

    // Return result
    if (pmatch[0].rm_eo - pmatch[0].rm_so == 0) {
        return NULL;
    }
    char* result = (char*) calloc(pmatch[0].rm_eo - pmatch[0].rm_so, sizeof(char));
    sprintf(result, "%.*s", pmatch[0].rm_eo - pmatch[0].rm_so, str + pmatch[0].rm_so);
    return result;
}

char* get_regex_of_token_id(token_id id) {
    switch (id) {
        case ID: return "[a-zA-Z][a-zA-Z0-9_]*";
        case INT_LIT: return "[0-9]+";
        case REAL_LIT: return "[0-9]+\\.[0-9]+";
        case STR_LIT: return "\"[^\t\n\r\"]*\"";
        case OP_AND: return "&&";
        case OP_OR: return "||";
        case OP_NOT: return "!!";
        case OP_IS: return "==";
        case OP_GR: return ">";
        case OP_LS: return "<";
        case OP_GRE: return ">=";
        case OP_LSE: return "<=";
        case OP_ADD: return "\\+";
        case OP_SUB: return "-";
        case OP_MUL: return "\\*";
        case OP_DIV: return "/";
        case OP_MOD: return "%";
        case OP_POW: return "\\^";
        case OP_FAC: return "!";
        case OP_IF: return "\\?";
        case CUR_BEG: return "\\(";
        case CUR_END: return "\\)";
        case BCE_BEG: return "\\{";
        case BCE_END: return "\\}";
        case COMMA: return ",";
        case SEMICOLON: return ";";
        case ASSIGN: return "=";
        case INFER: return "=>";
        default: return NULL;
    }
}

void remove_spaces(char* s) {
    char* d = s;
    do while(isspace(*s)) s++; while((*d++ = *s++));
}

void remove_comments(char *s) {
    // char* pattern = "//(^(\n))*\n";
    char* pattern = "//[^\n]*\n";
    regex_t regex;
    int msg;

    msg = regcomp(&regex, pattern, REG_EXTENDED);
    if (msg) {
        return;
    }

    char* new_s = NULL;

    while (1) {
        regmatch_t pmatch[1];
        msg = regexec(&regex, s, 1, pmatch, 0);
        if (msg) {
            return;
        }
        int new_s_length = strlen(s) - (pmatch[0].rm_eo - pmatch[0].rm_so);
        new_s = (char*) calloc(new_s_length, sizeof(char));
        sprintf(new_s, "%s%.*s%.*s",
            new_s,
            pmatch[0].rm_so, s + 0,
            (int)strlen(s) - pmatch[0].rm_eo, s + pmatch[0].rm_eo
        );
        
        sprintf(s, "%s", new_s);
        
        free(new_s);
        new_s = NULL;
    }
}

token_t* get_tokens_from(char* src) {
    char* f_match = NULL;
    
    remove_comments(src);
    remove_spaces(src);
    
    while (1) {

        token_t token;
        token.id = BEGIN_PLACEHOLDER;
        token.src = NULL;

        for (token_id id = BEGIN_PLACEHOLDER + 1; id < END_PLACEHOLDER; id++) {
            f_match = get_first_match(src, get_regex_of_token_id(id));
            if (f_match != NULL) {
                token.id = id;
                token.src = (char*) calloc(strlen(f_match), sizeof(char));
                sprintf(token.src, "%s", f_match);
                break;
            }
        }

        if (f_match == NULL) {
            printf("\n");
            return 0;
        }
        sprintf(src, "%.*s", (int)(strlen(src) - strlen(f_match)), src + strlen(f_match));
        free(f_match);

        printf("%s ", token.src);
    }
}