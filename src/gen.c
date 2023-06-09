#include "includes/gen.h"
#include <stdio.h>

void mips_init(FILE * f) {
	// data
	fprintf(f, "\t.data\n");
	fprintf(f, "cs: word 0:2048\n");
	// text
	fprintf(f, "\t .text\n");
	fprintf(f, "main:\n");
	fprintf(f, "\tla   $s0, cs\n");
}

void pop(FILE * f, char * reg) {
	fprintf(f, "\tlw   $%s, 0($sp)\n", reg);
	fprintf(f, "\taddi $sp, $sp, 0\n");
}

void push(FILE * f, char * reg) {
	fprintf(f, "\taddi $sp, $sp, -4\n");
	fprintf(f, "\tsw   $%s, 0($sp)\n", reg);
}

// ARITHMETIC Operations
void mips_add(FILE * f) {
	pop(f, "t0");
	pop(f, "t1");
	fprintf(f, "\tadd  $t0, $t0, $t1\n");
	push(f, "t0");
}

void mips_sub(FILE * f) {
	pop(f, "t0");
	pop(f, "t1");
	fprintf(f, "\tsub  $t0, $t0, $t1\n");
	push(f, "t0");
}

void mips_mul(FILE * f) {
	pop(f, "t0");
	pop(f, "t1");
	fprintf(f, "\tmul  $t0, $t0, $t1\n");
	push(f, "t0");
}

void mips_div(FILE * f) {
	pop(f, "t0");
	pop(f, "t1");
	fprintf(f, "\tdiv  $t0, $t1\n");
	fprintf(f, "\tmflo $t0\n");
	push(f, "t0");
}

void mips_mod(FILE * f) {
	pop(f, "t0");
	pop(f, "t1");
	fprintf(f, "\tdiv  $t0, $t1\n");
	fprintf(f, "\tmfhi $t0\n");
	push(f, "t0");
}

// STACK MANIPULATION Operations
void mips_dup(FILE * f) {
	pop(f, "t0");
	push(f, "t0"); push(f, "t0");
}

void mips_drop(FILE * f) {
	fprintf(f, "\taddi $sp, $sp, 4\n");
}

void mips_swap(FILE * f) {
	pop(f, "t0");
	pop(f, "t1");
	push(f, "t0");
	push(f, "t1");
}

void mips_push(FILE * f, int n) {
	fprintf(f, "\tli   $t0, %d\n", n);
	push(f, "t0");
}

void mips_copy(FILE * f, int n) {
	fprintf(f, "\tlw   $t0, %d($sp)\n", 4 * n);
	push(f, "t0");
}

void mips_slide(FILE * f, int n) {
	fprintf(f, "\tlw   $t0, 0($sp)\n");
	fprintf(f, "\taddi $sp, $sp, %d\n", (n+1) * 4);
	push(f, "t0");
}


// FLOW CONTROL Commands
void mips_label(FILE * f, int n) {
	fprintf(f, "label%d:\n", n);
}

void mips_call(FILE * f, int n) {
	fprintf(f, "\tsw   $ra, 0($s0)\n");
	fprintf(f, "\taddi $s0, $s0, 4\n");
	fprintf(f, "\tjal  label%d\n", n);
}

void mips_jmp(FILE * f, int n) {
	fprintf(f, "\tj    label%d\n", n);
}

void mips_jmpneg(FILE * f, int n) {
	fprintf(f, "\tlw   $t0, 0($sp)\n");
	fprintf(f, "\tbltz $t0, label%d\n", n);
}

void mips_jmpz(FILE * f, int n) {
	fprintf(f, "\tlw   $t0, 0($sp)\n");
	fprintf(f, "\tbeqz $t0, label%d\n", n);
}

void mips_return(FILE * f) {
	fprintf(f, "\tlw   $ra, 0($s0)\n");
	fprintf(f, "\taddi $s0, $s0, -4\n");
	fprintf(f, "\tjr   $ra\n");
}

void mips_exit(FILE * f) {
	fprintf(f, "\tli $v0, 10\n");
	fprintf(f, "\tsyscall\n");
}