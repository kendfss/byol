#include <stdio.h>
#include <string.h>

#include "values.c"

long exponentiate(long left, long right) {
    if (right == 0) {
        return 1;
    }
    return left * exponentiate(left, right - 1);
}

bval eval_op(bval x, char* op, bval y) {
    if (x.type == VAL_ERR) {
        return x;
    }
    if (y.type == VAL_ERR) {
        return y;
    }

    if (strcmp(op, "+") == 0) {
        return bval_num(x.num + y.num);
    }

    if (strcmp(op, "-") == 0) {
        return bval_num(x.num - y.num);
    }

    if (strcmp(op, "*") == 0) {
        return bval_num(x.num * y.num);
    }

    if (strcmp(op, "/") == 0) {
        return y.num == 0 ? bval_err(ERR_DIV_ZERO) : bval_num(x.num / y.num);
    }

    if (strcmp(op, "%") == 0) {
        return bval_num(x.num % y.num);
    }

    if (strcmp(op, "^") == 0) {
        return bval_num(exponentiate(x.num, y.num));
    }

    return bval_err(ERR_BAD_OP);
}
