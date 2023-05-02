#include <stdio.h>
#include <stdlib.h>
#include "src/includes/common.h"
#include "src/includes/token.h"
#include "src/includes/lexer.h"

int main(int argc, char const *argv[]) {
    if (argc <= 1) return 1;

    if      (streq(argv[1], "help"))   printf("help\n");
    else if (streq(argv[1], "lexer"))  printf("lexer\n");
    else if (streq(argv[1], "parser")) printf("parser\n");
    else if (streq(argv[1], "run"))    printf("run\n");
    return 0;
}