#include <stdio.h>
#include "includes/ast.h"

// Construct an Input/Output command with no parameters
Instr make_io(IOCmd cmd) {
    Instr i = {IO, { .io = cmd }, 0};
    return i;
}

// Construct a Stack command with no parameters
Instr make_stack(STACKCmd cmd) {
    Instr i = {STACK, { .stack = cmd}, 0};
    return i;
}

// Construct a Stack command with a integer parameter
Instr make_stack_param(STACKCmd cmd, int param) {
    Instr i = {STACK, { .stack = cmd}, param};
    return i;
}

// Construct an Arithmetic command with no parameters
Instr make_arith(ARITHCmd cmd) {
    Instr i = {ARITH, { .arith = cmd}, 0};
    return i;
}

// Construct a Flow Control command with no parameters
Instr make_flow(FLOWCmd cmd) {
    Instr i = {FLOW, { .flow = cmd}, 0};
    return i;
}

// Construct a Flow Control command with a integer paramter
Instr make_flow_param(FLOWCmd cmd, int param)  {
    Instr i = {FLOW, { .flow = cmd}, param};
    return i;
}

// Construct a Heap command with no parameters
Instr make_heap(HEAPCmd cmd)  {
    Instr i = {HEAP, { .heap = cmd}, 0};
    return i;
}


// Print an Input/Output Command
void print_io(Instr * instr) {
    if (instr == NULL) return;
    switch (instr->cmd.io) {
    case READC: puts("Read Character"); break;
    case READI: puts("Read Integer")  ; break;
    case SHOWC: puts("Show Character"); break;
    case SHOWI: puts("Show Integer")  ; break;
    }
}

// Print a Stack Command
void print_stack(Instr * instr) {
    if (instr == NULL) return;
    switch (instr->cmd.stack) {
    case PUSH : printf("Push %d\n", instr->param) ; break;
    case DUP  : printf("Duplicate\n")            ; break;
    case SWAP : printf("Swap\n")                 ; break; 
    case DROP : printf("Drop\n")                 ; break;
    case COPY : printf("Copy %d\n", instr->param) ; break;
    case SLIDE: printf("Slide %d\n", instr->param); break;
    }
}

// Print an Arithmetic Command
void print_arith(Instr * instr) {
    if (instr == NULL) return;
    switch (instr->cmd.arith) {
    case ADD: puts("ADD"); break;
    case SUB: puts("SUB"); break;
    case MUL: puts("MUL"); break;
    case DIV: puts("DIV"); break;
    case MOD: puts("MOD"); break;
    }
}

// Print a Flow Control Command
void print_flow(Instr * instr) {
    if (instr == NULL) return;
    switch (instr->cmd.flow) {
    case LABEL : printf("Label lbl%d\n", instr->param)        ; break;
    case CALL  : printf("Call lbl%d\n", instr->param)         ; break;
    case JMP   : printf("Goto lbl%d\n", instr->param)         ; break;  
    case JMPZ  : printf("If (= 0) goto lbl%d\n", instr->param); break; 
    case JMPNEG: printf("If (< 0) goto lbl%d\n", instr->param); break; 
    case RETURN: printf("Return\n")                          ; break; 
    case EXIT  : printf("Exit\n")                            ; break; 
    }
}

// Print an Heap Command
void print_heap(Instr * instr) {
    if (instr == NULL) return;
    switch (instr->cmd.heap) {
    case STORE   : puts("Store")   ; break;
    case RETRIEVE: puts("Retrieve"); break;
    }
}

// Print a command
void print_instr(Instr * instr) {
    if (instr == NULL) return;
    switch (instr->imp) {
    case IO   : print_io(instr)   ; break;
    case STACK: print_stack(instr); break;
    case ARITH: print_arith(instr); break;
    case FLOW : print_flow(instr) ; break;
    case HEAP : print_heap(instr) ; break;
    }
}