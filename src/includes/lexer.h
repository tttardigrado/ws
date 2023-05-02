#ifndef LEXER_H
#define LEXER_H

#include "token.h"
#include <stdbool.h>

// Lexer data structure -- keeps track of the content and it's position
typedef struct {
    char * current;
    unsigned row, col;
} Lexer;

// Init a new lexer with a given content
void  lexer_init(char * content);

// Check if the content of the lexer was consumed in it's totality
bool  lexer_is_at_end();

// Consume and return the next char
char  lexer_eat();

// Get the current character without modifying the lexer
char  lexer_cur();

// Ignore non-whitespace characters
void  lexer_ignore();

// Get the next token from the stream
Token lexer_get_tok();

#endif  // LEXER_H