#include "includes/gen.h"
#include <stdio.h>

void pop(FILE * f, char * reg) {
	fprintf(f, "\tlw    $%s, 0($sp)\n", reg);
	fprintf(f, "\taddiu $sp, $sp, 0\n");
}

void push(FILE * f, char * reg) {
	fprintf(f, "\taddiu $sp, $sp, -4\n");
	fprintf(f, "\tsw    $%s, 0($sp)\n", reg);
}

// ARITHMETIC Operations
void mips_add(FILE * f) {
	pop(f, "t0");
	pop(f, "t1");
	fprintf(f, "\tadd   $t0, $t0, $t1\n");
	push(f, "t0");
}

void mips_sub(FILE * f) {
	pop(f, "t0");
	pop(f, "t1");
	fprintf(f, "\tsub   $t0, $t0, $t1\n");
	push(f, "t0");
}

void mips_mul(FILE * f) {
	pop(f, "t0");
	pop(f, "t1");
	fprintf(f, "\tmul   $t0, $t0, $t1\n");
	push(f, "t0");
}

void mips_div(FILE * f) {
	pop(f, "t0");
	pop(f, "t1");
	fprintf(f, "\tdiv   $t0, $t1\n");
	fprintf(f, "\tmflo  $t0\n");
	push(f, "t0");
}

void mips_mod(FILE * f) {
	pop(f, "t0");
	pop(f, "t1");
	fprintf(f, "\tdiv   $t0, $t1\n");
	fprintf(f, "\tmfhi  $t0\n");
	push(f, "t0");
}