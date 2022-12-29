#include <string.h>

#include "../../../orangeduck/mpc/mpc.h"

#include "lexing.c"
#include "oprs.c"
#include "values.c"

bval eval(mpc_ast_t* t) {
    if (strstr(t->tag, "number")) {
        errno  = 0;
        long x = strtol(t->contents, NULL, 10);
        return errno != ERANGE ? bval_num(x) : bval_err(ERR_BAD_NUM);
    }

    char* op = t->children[1]->contents;
    bval  x  = eval(t->children[2]);

    int i = 3;
    while (strstr(t->children[i]->tag, "expr")) {
        x = eval_op(x, op, eval(t->children[i]));
        i++;
    }

    return x;
}
