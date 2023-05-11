#include <stdio.h>
#include <stdlib.h>
#include "includes/parser.h"
#include "includes/lexer.h"
#include "includes/token.h"
#include "includes/ast.h"
#include "includes/common.h"

void parser_error(const char * msg, Token * tok1) {
    fprintf(stderr, "%s: [%s]", msg, ws_string[tok1->kind]);
    exit(1);
}

void parser_error2(const char * msg, Token * tok1, Token * tok2) {
    fprintf(stderr, "%s: [%s][%s]", msg, ws_string[tok1->kind], ws_string[tok2->kind]);
    exit(1);
}

Instr parser_get_instr() {
    Token tok1 = lexer_get_tok();

    if (is_kind(tok1, SPACE)) return parse_stack();
    if (is_kind(tok1, LINE )) return parse_flow();

    Token tok2 = lexer_get_tok();

    if (is_kind(tok1, TAB)) {
        if (is_kind(tok2, SPACE)) return parse_arith();
        if (is_kind(tok2, TAB  )) return parse_heap();
        if (is_kind(tok2, LINE )) return parse_io();
    }
    parser_error2("Invalid IMP: ", &tok1, &tok2);
}

Instr parse_io() {
    Token tok1 = lexer_get_tok();
    Token tok2 = lexer_get_tok();

    if (is_kind(tok1, TAB)) {
        if (is_kind(tok2, SPACE)) return make_io(READC);
        if (is_kind(tok2, TAB  )) return make_io(READI);
    }
    else if (is_kind(tok1, SPACE)) {
        if (is_kind(tok2, SPACE)) return make_io(SHOWC);
        if (is_kind(tok2, TAB  )) return make_io(SHOWI);
    }

    parser_error2("Invalid IO Command: ", &tok1, &tok2);
}

Instr parse_stack() {
    Token tok1 = lexer_get_tok();

    if (is_kind(tok1, SPACE))
        return make_stack_param(PUSH, parse_signed());

    Token tok2 = lexer_get_tok();

    if (is_kind(tok1, LINE)) {
        if (is_kind(tok2, SPACE)) return make_stack(DUP);
        if (is_kind(tok2, TAB  )) return make_stack(SWAP);
        if (is_kind(tok2, LINE )) return make_stack(DROP);
    }
    else if (is_kind(tok1, TAB)) {
        if (is_kind(tok2, SPACE))
            return make_stack_param(COPY, parse_signed());
        if (is_kind(tok2, LINE))
            return make_stack_param(SLIDE, parse_signed());
    }

    parser_error2("Invalid STACK Command: ", &tok1, &tok2);
}

Instr parse_flow() {
    Token tok1 = lexer_get_tok();
    Token tok2 = lexer_get_tok();


    if (is_kind(tok1, SPACE)) {
        if (is_kind(tok2, SPACE))
            return make_flow_param(LABEL, parse_unsigned());
        if (is_kind(tok2, TAB))
            return make_flow_param(CALL, parse_unsigned());
        if (is_kind(tok2, LINE))
            return make_flow_param(JMP, parse_unsigned());
    }
    else if (is_kind(tok1, TAB)) {
        if (is_kind(tok2, SPACE))
            return make_flow_param(JMPZ, parse_unsigned());
        if (is_kind(tok2, TAB))
            return make_flow_param(JMPNEG, parse_unsigned());
        if (is_kind(tok2, LINE))
            return make_flow(RETURN);
    }
    else if (is_kind(tok1, LINE) && is_kind(tok2, LINE)) {
        return make_flow(EXIT);
    }

    parser_error2("Invalid FLOW Command", &tok1, &tok2);
}

Instr parse_arith() {
    Token tok1 = lexer_get_tok();
    Token tok2 = lexer_get_tok();

    if (is_kind(tok1, SPACE)) {
        if (is_kind(tok2, SPACE)) return make_arith(ADD);
        if (is_kind(tok2, TAB  )) return make_arith(SUB);
        if (is_kind(tok2, LINE )) return make_arith(MUL);
    }
    else if (is_kind(tok1, TAB)) {
        if (is_kind(tok2, SPACE)) return make_arith(DIV);
        if (is_kind(tok2, TAB  )) return make_arith(MOD);
    }

    parser_error2("Invalid ARITH Command: ", &tok1, &tok2);
}

Instr parse_heap() {
    Token tok = lexer_get_tok();

    if (is_kind(tok, SPACE)) return make_heap(STORE);
    if (is_kind(tok, TAB  )) return make_heap(RETRIEVE);

    parser_error("Invalid HEAP Command: ", &tok);
}

int parse_signed() {
    Token tok = lexer_get_tok();
    int sign = tok.kind == TAB ? -1 : 1;

    return sign * parse_unsigned();
}

int parse_unsigned() {
    Token tok;
    int res = 0;

    while((tok = lexer_get_tok()).kind != LINE)
    	if (tok.kind == END)
    		parser_error("Invalid Parameter", &tok);
    	else
    		res = tok.kind == TAB ? res * 2 + 1 : res * 2;

    return res;
}

