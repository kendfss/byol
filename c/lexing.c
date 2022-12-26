#include "../../../orangeduck/mpc/mpc.h"

// int max(int items[]){
//     int val = 0;
//     for
// }

int most_children(mpc_ast_t* t) {
    int out = 0;

    // if (t->children_num)

    return out;
}

int nnodes(mpc_ast_t* t) {
    if (t->children_num == 0) {
        return 1;
    }
    // if (t->children_num > 0) {
    int total = 1;
    for (int i = 0; i < t->children_num; i++) {
        total += nnodes((t->children[i]));
    }
    return total;
    // }
    // return 0;
}

int nleaves(mpc_ast_t* t) {
    int out = 0;

    if (strcmp(t->contents, "") != 0) {
        out++;
    }

    for (int i = 0; i < t->children_num; i++) {
        out += nleaves(t->children[i]);
    }

    return out;
}

int nbranches(mpc_ast_t* t) {
    int out = 0;

    if (strcmp(t->contents, "") == 0) {
        out++;
    }

    for (int i = 0; i < t->children_num; i++) {
        out += nbranches(t->children[i]);
    }

    return out;
}

int nchildren(mpc_ast_t* t) {
    int out = 0;

    if (t->children_num > 0) {
        out += t->children_num;
    }

    for (int i = 0; i < t->children_num; i++) {
        out += nbranches(t->children[i]);
    }

    return out;
}
