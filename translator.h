#pragma once
#include "tokenizer.h"

struct n_instr {
    int ifgoto;
    int push;
    int pop;
    int function;
    int call;
    int ret;
    int lt;
    int gt;
    int eq;
    int neg;
    int and;
    int or;
    int not;
    int add;
    int sub;
};

void translator(FILE* dest, string_ll* tokens, char* filename, char isdir);
//translates and writes the tokens into the destination file

void initialize(FILE* dest, char isdir);
//initializes the stack and makes the initial system calls on the .asm file