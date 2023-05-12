#include <stdio.h>
#include <stdlib.h>
#include "src/includes/common.h"
#include "src/includes/token.h"
#include "src/includes/lexer.h"
#include "src/includes/ast.h"
#include "src/includes/parser.h"

int main(int argc, char const *argv[]) {
    //if (argc <= 2) return 1;

    char * source = readFile(argv[1]);      // read source file
    FILE * output = openWriteFile(argv[2]); // open output file
    
    lexer_init(source);                     // init lexer

    // parse the source file and generate asm for every parsed instruction
    while (!lexer_is_at_end()) {
     	Instr instr = parser_get_instr();
     	print_instr(&instr);
    	lexer_ignore();
    }

    free(source);
     fclose(output);
    return 0;
}