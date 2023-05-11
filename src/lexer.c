#include "includes/lexer.h"
#include "includes/token.h"
#include "includes/common.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

static Lexer lex;

void lexer_error(const char * msg, unsigned row, unsigned col) {
    fprintf(stderr, "%s at line %d column %d\n", msg, row, col);
    exit(1);
}

// Init a new lexer with a given content
void lexer_init(char * content) {
    lex.current = content;
    lex.col = 0;
    lex.row = 0;
}

// Check if the content of the lexer was consumed in it's totality
bool lexer_is_at_end() {
    return *lex.current == '\0';
}

// Consume and return the next char
char lexer_eat() {
    lex.current++;
    lex.col++;
    return lex.current[-1];
}

// Get the current character without modifying the lexer
char  lexer_cur() {
    return *lex.current;
}

// Ignore non-whitespace characters
void  lexer_ignore() {
    while(!(lexer_is_at_end() || is_valid(lexer_cur()))) {
        lex.current++;
        lex.col++;
    }
};

// Get the next token from the stream
Token lexer_get_tok() {
    lexer_ignore();

    // return a special token to mark the end of the token stream
    if (lexer_is_at_end()) return token_new(END, lex.row, lex.col-1);

    // return a token based on the character found
    switch (lexer_eat()){
    case ' ' : return token_new(SPACE, lex.row, lex.col-1);
    case '\t': return token_new(TAB  , lex.row, lex.col-1);
    case '\n':
        Token tok = token_new(LINE, lex.row, lex.col-1);
        lex.col = 0; lex.row++; // go back to the start of the line and increment the line number
        return tok;
    }

    // if none of the previous matched something wrong happened
    lexer_error("An error ocurred while Lexing", lex.row, lex.col - 1);
}
