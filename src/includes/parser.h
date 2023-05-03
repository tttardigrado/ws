#ifndef PARSER_H
#define PARSER_H

#include "token.h"
#include "ast.h"

Instr parser_get_instr();

Instr parse_io();
Instr parse_stack();
Instr parse_flow();
Instr parse_arith();
Instr parse_heap();

int parse_signed();
int parse_unsigned();

#endif  // PARSER_H