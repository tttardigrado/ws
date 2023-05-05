#include <stdio.h>
#include <stdlib.h>
#include "src/includes/common.h"
#include "src/includes/token.h"
#include "src/includes/lexer.h"
#include "src/includes/ast.h"
#include "src/includes/parser.h"

int main(int argc, char const *argv[]) {
    //if (argc <= 2) return 1;

    char * source = "   \na \n a\t\n\t\t";//readFile(argv[1]);
    //FILE * output = openWriteFile(argv[2]);
    lexer_init(source);
    
    while (!lexer_is_at_end()) {
        //Token tok = lexer_get_tok();
        //puts(ws_string[tok.kind]);
        Instr instr = parser_get_instr();
        print_instr(&instr);
    }

    // free(source);
    // fclose(output);
    return 0;
}