#ifndef AST_H
#define AST_H

// Instruction Modification Parameters
typedef enum { IO, STACK, ARITH, FLOW, HEAP } IMP;

typedef enum { READC, READI, SHOWC, SHOWI } IOCmd ;

typedef enum { PUSH, DUP, SWAP, DROP, COPY, SLIDE } STACKCmd;

typedef enum { ADD, SUB, MUL, DIV, MOD} ARITHCmd;

typedef enum { LABEL, CALL, JMP, JMPZ, JMPNEG, RETURN, EXIT} FLOWCmd;

typedef enum { STORE, RETRIEVE } HEAPCmd;

typedef struct {
    IMP imp;
    union {
        IOCmd    io;
        STACKCmd stack;
        ARITHCmd arith;
        FLOWCmd  flow;
        HEAPCmd  heap;
    } cmd;
    int param;
} Instr;

// Constructor functions
Instr make_io(IOCmd cmd);
Instr make_stack(STACKCmd cmd);
Instr make_stack_param(STACKCmd cmd, int param);
Instr make_arith(ARITHCmd cmd);
Instr make_flow(FLOWCmd cmd);
Instr make_flow_param(FLOWCmd cmd, int param);
Instr make_heap(HEAPCmd cmd);

// Print functions
void print_io(Instr * instr);
void print_stack(Instr * instr);
void print_arith(Instr * instr);
void print_flow(Instr * instr);
void print_heap(Instr * instr);
void print_instr(Instr * instr);

#endif  // AST_H