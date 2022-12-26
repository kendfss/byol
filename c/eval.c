#include <string.h>

#include "../../../orangeduck/mpc/mpc.h"

#include "lexing.c"
#include "oprs.c"

long eval(mpc_ast_t* t) {
    if (strstr(t->tag, "number")) {
        return atoi(t->contents);
    }

    char* op = t->children[1]->contents;

    long x = eval(t->children[2]);

    int i = 3;

    while (strstr(t->children[i]->tag, "expr")) {
        x = eval_op(x, op, eval(t->children[i]));
        i++;
    }

    if (i == 3 && strcmp(op, "-") == 0) {
        x = eval_op(x, op, 0);
    }

    return x;
}
