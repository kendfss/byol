- Write a regular expression matching strings of all a or b such as aababa or bbaa.
    + `[ab]+`
- Write a regular expression matching strings of consecutive a and b such as ababab or aba.
    + `(a[ab]+)+`
        * assuming runs of `a` are allowed.
- Write a regular expression matching pit, pot and respite but not peat, spit, or part.
    + `pit|pot|respite` - sorry. Can't tell how to differentiate _respite_ and _spit_!
- Change the grammar to add a new operator such as %.
    + `#` == reference pointer
    + `@` == dereference pointer
    + `!` == not
    + ```c
        "                                                                               \
            dot         : '.' ;                                                         \
            neg         : '-' ;                                                         \
            lparen      : '(' ;                                                         \
            rparen      : ')' ;                                                         \
            lbrace      : '{' ;                                                         \
            rbrace      : '}' ;                                                         \
            lbrack     : '[' ;                                                          \
            rbrack     : ']' ;                                                          \
            digit       : '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9' ;   \
            operator    : '+' | '-' | '*' | '/' | '%' | '#' | '@' |;                    \
            number      : <neg>? <digit>+ ;                                             \
            expr        : <number> | <lparen> <operator> <expr>+ <rparen> ;             \
            byol        : /^/ <operator> <expr>+ /$/ ;                                  \
        ";
        ```

- Change the grammar to recognise operators written in textual format add, sub, mul, div.
    + ```c
        char* specLines[] = {
            "dot      : '.'", 
            "neg      : '-'", 
            "lparen   : '('",
            "rparen   : ')'",
            "lbrace   : '{'",
            "rbrace   : '}'",
            "lbrack   : '['",
            "rbrack   : ']'",
            "comment  : '/' '/'",
            "add      : '+' | 'a' 'd' 'd'",
            "sub      : '-' | 's' 'u' 'b'",
            "mul      : '*' | 'm' 'u' 'l'",
            "div      : '/' | 'd' 'i' 'v'",
            "mod      : '%' | 'm' 'o' 'd'",
            "ref      : '#' | 'p' 't' 'r'",
            "val      : '@' | 'v' 'a' 'l'",
            "not      : '!' | 'n' 'o' 't'",
            "exp      : '*' '*' | 'e' 'x' 'p'",
            "or       : '|' '|' | 'o' 'r'",
            "and      : '&' '&' | 'a' 'n' 'd'",
            "band     : '&' | 'a' 'n' 'd'",
            "bor      : '|' | 'o' 'r'",
            "xor      : '^' | 'x' 'o' 'r'",
            "digit    : '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'",
            "operator : <add> | <sub> | <mul> | <div> | <mod> | <exp> | <ref> | <val> | <and> | <or> | <not> | <band> | <bor> | <xor>",
            "number   : <neg>? <digit>+",
            "expr     : <number> | <lparen> <operator> <expr>+ <rparen>",
            "byol     : /^/ <operator> <expr>+ /$/"
        };
    ```
- Change the grammar to recognize decimal numbers such as 0.01, 5.21, or 10.2.
    + ```c
        "number   : <neg>? <digit>* <dot>? <digit>+",
    ```
- Change the grammar to make the operators written conventionally, between two expressions.
    + ```c
        "byol     : /^/ <operator> <expr>+ | <expr> <operator> <expr> /$/"
    ```
- Use the grammar from the previous chapter to parse Doge. You must add start and end of input.
