#pragma once

// #include <cstdio>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
    #include "lines_windows.h"
#else
    #include "lines_unix.h"
#endif

#include "../../../orangeduck/mpc/mpc.c"

#include "errors.c"
#include "eval.c"
#include "utils.c"
#include "values.c"

int prompt(char* name, char* version) {

    mpc_parser_t* Number   = mpc_new("number");
    mpc_parser_t* Operator = mpc_new("operator");
    mpc_parser_t* Expr     = mpc_new("expr");
    mpc_parser_t* Byol     = mpc_new("byol");

    // clang-format off
    char* specSep     = " ; \n";
    char* specLines[] = {
        "number      : /[0-9]+/ | '-' <number>",
        "operator    : '+' | '-' | '*' | '/' | '^' | '%' | '^'",
        "expr        : <number> | '(' <operator> <expr>+ ')'",
        "byol        : /^/ <operator> <expr>+ /$/",
    };
    // clang-format on

    const char* spec =
        join(specSep, specLines, sizeof(specLines) / sizeof(specLines[0]));

    mpca_lang(MPCA_LANG_DEFAULT, spec, Number, Operator, Expr, Byol);

    printf("%s version %s\n", name, version);
    puts("press ctrl+c to exit\n");

    while (1) {
        char* input = readline(">> ");
        if (strlen(input) == 0 || strcmp(input, "!q") == 0) {
            break;
        }
        add_history(input);

        mpc_result_t r;
        if (mpc_parse("<stdin>", input, Byol, &r)) {
            // mpc_ast_print(r.output);
            mpc_ast_t* ast = r.output;

            int leaves   = nleaves(ast);
            int branches = nbranches(ast);
            int nodes    = nnodes(ast);

            // int children = nchildren(ast);
            // if (children != nodes + 1) {
            //     // err_child_count(ast, children, nodes);
            //     // char* err = err_child_count(ast, children, nodes);
            //     char* err = err_child_count(children, nodes);
            //     puts(err);
            //     free(err);
            //     mpc_ast_print(ast);
            //     break;
            // }

            if (nodes != leaves + branches) {
                // err_branch_leaf_count(ast, branches, leaves, nodes);
                // char* err = err_branch_leaf_count(ast, branches, leaves, nodes);
                char* err = err_branch_leaf_count(branches, leaves, nodes);
                puts(err);
                free(err);
                mpc_ast_print(ast);
                break;
            }

            bval result = eval(ast);
            bval_println(result);
            mpc_ast_delete(r.output);
        } else {
            mpc_err_print(r.error);
            mpc_err_delete(r.error);
        }

        free(input);
    }
    mpc_cleanup(4, Number, Operator, Expr, Byol);
    return 0;
}
