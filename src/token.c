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
    switch (tok->kind) {
        case SPACE: printf("SPACE (%u, %u)\n", tok->row, tok->col); break;
        case TAB  : printf("TAB   (%u, %u)\n"  , tok->row, tok->col); break;
        case LINE : printf("Line  (%u, %u)\n" , tok->row, tok->col); break;
        case END  : printf("EOF   (%u, %u)\n"  , tok->row, tok->col); break;
        default   : printf("\033[0;31mERROR (%u, %u)\033[0m\n" , tok->row, tok->col); // print errors in red
    }
}

// Print a simplified version of the token (only kind) 
void token_print(Token * tok) {
    switch (tok->kind) {
        case SPACE: putchar('S'); break;
        case TAB  : putchar('T'); break;
        case LINE : putchar('L'); break;
        case END  : putchar('E'); break;
        default   : printf("\033[0;31mERR\033[0m"); // print errors in red
    }
}

// Check if a character is a valid token (' ', '\n', '\t') 
bool is_valid(char c) {
    return c == ' ' || c == '\n' || c == '\t';
}

bool is_kind(Token tok, WS kind) {
    return tok.kind == kind;
}

bool is_kind2(Token tok1, Token tok2, WS kind1, WS kind2) {
    return tok1.kind == kind1 && tok2.kind == kind2;
}