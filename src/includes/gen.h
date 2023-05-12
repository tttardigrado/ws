#ifndef GEN_H
#define GEN_H
#include <stdio.h>

void mips_add(FILE * f);
void mips_sub(FILE * f);
void mips_mul(FILE * f);
void mips_div(FILE * f);
void mips_mod(FILE * f);

void mips_store(FILE * f);
void mips_retrieve(FILE * f);

void mips_dup(FILE * f);
void mips_drop(FILE * f);
void mips_swap(FILE * f);
void mips_push(FILE * f, int n);
void mips_copy(FILE * f, int n);
void mips_slide(FILE * f, int n);

void mips_label(FILE * f, int n);
void mips_call(FILE * f, int n);
void mips_jmp(FILE * f, int n);
void mips_jmpneg(FILE * f, int n);
void mips_jmpz(FILE * f, int n);
void mips_return(FILE * f);
void mips_exit(FILE * f);

void mips_read_int(FILE * f);
void mips_show_int(FILE * f);
void mips_read_chr(FILE * f);
void mips_show_chr(FILE * f);
#endif  // GEN_H