#ifndef PARSER_H
#define PARSER_H

#include "token.h"
#include "ast.h"

// Report Parser Errors and exit
void parser_errror(const char * msg, Token * tok1, Token * tok2);

// Parse a full instruction
Instr parser_get_instr();

// Parser for specific IMP patterns
Instr parse_io();
Instr parse_stack();
Instr parse_flow();
Instr parse_arith();
Instr parse_heap();

// Parse integers
int parse_signed();
int parse_unsigned();

#endif  // PARSER_H