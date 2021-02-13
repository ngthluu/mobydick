#include <stdio.h>
#include <stdlib.h>

#include "lexer/lexer.h"

char* get_text_from_file(char* filepath) {
    // Read source file
    FILE* fp;
    char* src;
    long src_bytes;

    // Open an existing file to read
    fp = fopen(filepath, "r");
    if (fp == NULL) {
        return NULL;
    }

    // Get the number of bytes
    fseek(fp, 0L, SEEK_END);
    src_bytes = ftell(fp);

    // Reset the file position to the beginning of the file
    fseek(fp, 0L, SEEK_SET);
    
    // Allocate the buffer
    src = (char*) calloc(src_bytes, sizeof(char));
    if (src == NULL) {
        return NULL;
    }

    // Copy the text of the file to the buffer
    fread(src, sizeof(char), src_bytes, fp);
    fclose(fp);

    return src;
}

int main() {

    char* src = get_text_from_file("sample-src.moby");
    if (src == NULL) {
        return 1;
    }
    
    g

    free(src);
    return 0;
}