#include "includes/token.h"
#include <stdio.h>
#include <stdbool.h>

// Constructor for a new token
Token token_new(WS kind, unsigned row, unsigned col) {
    Token t = {kind, row, col};
    return t;
}

// Print a token ended by a new line
void token_print(Token * tok) {
    switch (tok->kind) {
        case SPACE: printf("SPACE (%u, %u)\n", tok->row, tok->col); break;
        case TAB  : printf("TAB   (%u, %u)\n"  , tok->row, tok->col); break;
        case LINE : printf("Line  (%u, %u)\n" , tok->row, tok->col); break;
        case END  : printf("EOF   (%u, %u)\n"  , tok->row, tok->col); break;
        default   : printf("ERROR (%u, %u)\n" , tok->row, tok->col);
    }
}

// Check if a character is a valid token (' ', '\n', '\t') 
bool is_valid(char c) {
    return c == ' ' || c == '\n' || c == '\t';
}