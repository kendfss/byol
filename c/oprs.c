#include <stdio.h>
#include <string.h>

long exponentiate(long left, long right) {
    if (right == 0) {
        return 1;
    }
    return left * exponentiate(left, right - 1);
}

long eval_op(long left, char* op, long right) {
    if (strcmp(op, "+") == 0) {
        return left + right;
    }

    if (strcmp(op, "-") == 0) {
        if (right == 0) {
            return -left;
        }
        if (left == 0) {
            return -right;
        }
        return left - right;
    }

    if (strcmp(op, "*") == 0) {
        return left * right;
    }

    if (strcmp(op, "/") == 0) {
        return left / right;
    }

    if (strcmp(op, "%") == 0) {
        return left % right;
    }

    if (strcmp(op, "^") == 0) {
        return exponentiate(left, right);
    }
    return 0;
}
