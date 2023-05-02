#ifndef TOKEN_H
#define TOKEN_H

#include <stdio.h>
#include <stdbool.h>

typedef enum { END, SPACE, TAB, LINE, ERROR } WS;

typedef struct {
    WS kind;
    unsigned row, col;
} Token;

Token token_new(WS kind, unsigned row, unsigned col);

void token_print(Token * tok);

bool is_valid(char c);

#endif // TOKEN_H