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
#include "utils.c"

int prompt(char* name, char* version) {

    mpc_parser_t* Dot = mpc_new("dot");
    mpc_parser_t* Comma = mpc_new("comma");
    mpc_parser_t* Neg = mpc_new("neg");
    mpc_parser_t* Lparen = mpc_new("lparen");
    mpc_parser_t* Rparen = mpc_new("rparen");
    mpc_parser_t* Lbrace = mpc_new("lbrace");
    mpc_parser_t* Rbrace = mpc_new("rbrace");
    mpc_parser_t* Lbrack = mpc_new("lbrack");
    mpc_parser_t* Rbrack = mpc_new("rbrack");
    mpc_parser_t* Comment = mpc_new("comment");

    mpc_parser_t* Ref = mpc_new("ref");
    mpc_parser_t* Val = mpc_new("val");
    mpc_parser_t* Lshift = mpc_new("lshift");
    mpc_parser_t* Rshift = mpc_new("rshift");

    mpc_parser_t* Add = mpc_new("add");
    mpc_parser_t* Sub = mpc_new("sub");
    mpc_parser_t* Mul = mpc_new("mul");
    mpc_parser_t* Div = mpc_new("div");
    mpc_parser_t* Mod = mpc_new("mod");
    mpc_parser_t* Exp = mpc_new("exp");

    mpc_parser_t* Band = mpc_new("band");
    mpc_parser_t* Bor = mpc_new("bor");
    mpc_parser_t* Xor = mpc_new("xor");
    mpc_parser_t* Not = mpc_new("not");
    mpc_parser_t* Or = mpc_new("or");
    mpc_parser_t* And = mpc_new("and");
    mpc_parser_t* Eq = mpc_new("eq");
    mpc_parser_t* Neq = mpc_new("neq");
    mpc_parser_t* Gt = mpc_new("gt");
    mpc_parser_t* Lt = mpc_new("lt");
    mpc_parser_t* Ge = mpc_new("ge");
    mpc_parser_t* Le = mpc_new("le");

    mpc_parser_t* Digit = mpc_new("digit");
    mpc_parser_t* Number = mpc_new("number");
    mpc_parser_t* Operator = mpc_new("operator");
    // mpc_parser_t* Binop = mpc_new("binop");
    mpc_parser_t* Expr = mpc_new("expr");
    mpc_parser_t* Byol = mpc_new("byol");

    char* specSep = " ; \n ";
    /* clang-format off */
    char* specLines[] = {
        "dot      : '.'", 
        "comma    : ','", 
        "neg      : '-'", 
        "lparen   : '('",
        "rparen   : ')'",
        "lbrace   : '{'",
        "rbrace   : '}'",
        "lbrack   : '['",
        "rbrack   : ']'",
        "comment  : '/' '/'",

        "ref      : '#' | 'r' 'e' 'f'",
        "val      : '@' | 'v' 'a' 'l'",

        "lshift   : '<' '<'",
        "rshift   : '>' '>'",

        "add      : '+' | 'a' 'd' 'd'",
        "sub      : '-' | 's' 'u' 'b'",
        "mul      : '*' | 'm' 'u' 'l'",
        "div      : '/' | 'd' 'i' 'v'",
        "mod      : '%' | 'm' 'o' 'd'",
        "exp      : '*' '*' | 'e' 'x' 'p'",

        "not      : '!' | 'n' 'o' 't'",
        "or       : '|' '|' | 'o' 'r'",
        "and      : '&' '&' | 'a' 'n' 'd'",
        "eq       : '=' '=' | 'e' 'q'",
        "neq      : '!' '=' | 'n' 'e' 'q'",
        "gt       : '>' | 'g' 't'",
        "lt       : '<' | 'l' 't'",
        "ge       : '>' '=' | 'g' 'e'",
        "le       : '<' '=' | 'l' 'e'",

        "band     : '&' | 'a' 'n' 'd'",
        "bor      : '|' | 'o' 'r'",
        "xor      : '^' | 'x' 'o' 'r'",

        "operator : <lshift> | <rshift> | <add> | <sub> | <mul> | <div> | <mod> | <exp> | <band> | <bor> | <xor> | <not> | <or> | <and> | <eq> | <neq> | <gt> | <lt> | <ge> | <le>",
        // "binop    : <operator>",
        // "unop     : <binop> | <unop>",
        // "operation: <binop> | <unop>",
        // "digit    : '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'",
        "digit    : /[0-9]/",
        // "number   : <neg>? <digit>+",
        // "number   : <neg>? (<digit>+ <dot>)? <digit>+ ",
        "number   : <neg>? <digit>+ | <number> <dot>? <digit>+",
        // "operation: <operator> <number>",
        // "number   : <neg>? <digit>+",
        "expr     : <number> | <expr> | <lparen> <operator> <expr>+ <rparen>",
        // "expr     : <number> | <lparen> <operator> <expr>+ <rparen> | <lparen>? <expr> <rparen> <",
        // "expr     : <number> | <lparen> <operator> <expr>+ <rparen> | <lparen>? <expr> <rparen>? <operator> <lparen>? <expr> <rparen>?",
        // "expr     : <number> | <lparen> <operator> <expr>+ <rparen> | <lparen> <expr> <rparen>",
        // "byol     : /^/ <operator> <expr>+ /$/"
        "byol     : /^/ <operator> <expr>+ | <expr> <operator> <expr> /$/"
    };
    /* clang-format on */
    const char* spec =
        join(specSep, specLines, sizeof(specLines) / sizeof(specLines[0]));

    mpca_lang(MPCA_LANG_DEFAULT, spec, Dot, Comma, Neg, Lparen, Rparen, Lbrace,
              Rbrace, Lbrack, Rbrack, Comment, Ref, Val, Lshift, Rshift, Add,
              Sub, Mul, Div, Mod, Exp, Band, Bor, Xor, Not, Or, And, Eq, Neq,
              Gt, Lt, Ge, Le, Digit, Number, Operator, Expr, Byol);

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
            mpc_ast_print(r.output);
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
