#ifndef TOKEN_H
#define TOKEN_H

#include <stdio.h>
#include <stdbool.h>

// Enum for the kinds of whitespace tokens
typedef enum {
    END,   // End of the src file
    SPACE, // ' '  - space
    TAB,   // '\t' - tab
    LINE,  // '\n' - new line
    ERROR  // Some error occured
} WS;

// Token with a kind and it's position on the file 
typedef struct {
    WS kind;
    unsigned row, col; // position
} Token;

// Constructor for a new token
Token token_new(WS kind, unsigned row, unsigned col);

// Print a token with position ended by a new line
void token_print_pos(Token * tok);

// Print a simplified version of the token (only kind) 
void token_print(Token * tok);

// Check if a character is a valid token
bool is_valid(char c);

bool is_kind(Token tok, WS kind);

#endif // TOKEN_H