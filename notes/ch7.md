- Write a recursive function to compute the number of leaves of a tree.
    + ```c
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
    ```
- Write a recursive function to compute the number of branches of a tree.
    + ```c
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
    ```
- Write a recursive function to compute the most number of children spanning from one branch of a tree.
- How would you use strstr to see if a node was tagged as an expr?
    + `strstr(node->tag, "expr") == 0 ? true : false`
- How would you use strcmp to see if a node had the contents '(' or ')'?
- Add the operator `%`, which returns the remainder of division. For example `% 10 6 is 4`.
- Add the operator `^`, which raises one number to another. For example `^ 4 2 is 16`.
- Add the function `min`, which returns the smallest number. For example `min 1 5 3` is 1.
- Add the function `max`, which returns the biggest number. For example `max 1 5 3` is 5.
- Change the minus operator - so that when it receives one argument it negates it.

