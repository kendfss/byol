#pragma once
#include <stdio.h>

typedef struct {
    int  type;
    long num;
    int  err;
} bval;

enum {
    VAL_NUM,
    VAL_ERR
}; // possible value types

enum {
    ERR_DIV_ZERO,
    ERR_BAD_OP,
    ERR_BAD_NUM
}; // possible error types

bval bval_num(long x) {
    bval v;
    v.type = VAL_NUM;
    v.num  = x;
    return v;
}

bval bval_err(int x) {
    bval v;
    v.type = VAL_ERR;
    v.err  = x;
    return v;
}

void bval_print(bval v) {
    switch (v.type) {
    case VAL_NUM:
        printf("%li", v.num);
        break;
    case VAL_ERR:
        switch (v.err) {
        case ERR_DIV_ZERO:
            printf("division by zero");
            break;
        case ERR_BAD_OP:
            printf("invalid operator");
            break;
        case ERR_BAD_NUM:
            printf("invalid number");
            break;
        }
        break;
    }
}

void bval_println(bval v) {
    bval_print(v);
    putchar('\n');
}
