#include "includes/token.h"
#include <stdio.h>
#include <stdbool.h>

// Constructor for a new token
Token token_new(WS kind, unsigned row, unsigned col) {
    Token t = {kind, row, col};
    return t;
}

// Print a token with position ended by a new line
void token_print_pos(Token * tok) {
    if (tok == NULL) return;

    switch (tok->kind) {
        case SPACE: printf("SPACE (%u, %u)\n", tok->row, tok->col); break;
        case TAB  : printf("TAB   (%u, %u)\n"  , tok->row, tok->col); break;
        case LINE : printf("Line  (%u, %u)\n" , tok->row, tok->col); break;
        case END  : printf("END   (%u, %u)\n" , tok->row, tok->col); break;
    }
}

// Print a simplified version of the token (only kind)
void token_print(Token * tok) {
    if (tok == NULL) return;

    switch (tok->kind) {
        case SPACE: putchar('S'); break;
        case TAB  : putchar('T'); break;
        case LINE : putchar('L'); break;
        case END  : putchar('E'); break;
    }
}

// Check if a character is a valid token (' ', '\n', '\t')
bool is_valid(char c) {
    return c == ' ' || c == '\n' || c == '\t';
}

bool is_kind(Token tok, WS kind) {
    return tok.kind == kind;
}