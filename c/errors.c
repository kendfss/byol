#include "../../../orangeduck/mpc/mpc.h"

#include "utils.c"

const int bufsize = 1024;

// char* err_branch_leaf_count(mpc_ast_t* ast, int branches, int leaves, int nodes) {
char* err_branch_leaf_count(int branches, int leaves, int nodes) {
    char* out = (char*)malloc(bufsize * sizeof(char));

    sprintf(out, "number of leaves does not agree with number of branches\n");
    sprintf(out + strlen(out), "\tnodes: %i\n", nodes);
    sprintf(out + strlen(out), "\tleaves: %i\n", leaves);
    sprintf(out + strlen(out), "\tbranches: %i\n", branches);

    // puts(out);
    // mpc_ast_print(ast);

    return out;
}

// char* err_child_count(mpc_ast_t* ast, int children, int nodes) {
char* err_child_count(int children, int nodes) {
    char* out = (char*)malloc(bufsize * sizeof(char));

    sprintf(out, "number of children does not agree with number of nodes\n");
    sprintf(out + strlen(out), "\tnodes: %i\n", nodes);
    sprintf(out + strlen(out), "\tchildren: %i\n", children);
    sprintf(out + strlen(out), "\t(difference should be one)");

    // puts(out);
    // mpc_ast_print(ast);

    return out;
}
