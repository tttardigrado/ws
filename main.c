#include <stdio.h>
#include <stdlib.h>
#include "src/includes/common.h"
#include "src/includes/token.h"
#include "src/includes/lexer.h"
#include "src/includes/ast.h"
#include "src/includes/parser.h"

int main(int argc, char const *argv[]) {
    if (argc <= 1) return 1;

    char * source = readFile(argv[1]);
    lexer_init(source);
    
    while (!lexer_is_at_end()) {
        Instr instr = parser_get_instr();
        print_instr(instr);
    }

    free(source);
    return 0;
}