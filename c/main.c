#include <stdio.h>

static char input[2048];
char* name = "byol";
char* version = "0.0.1";
int main(int argc, char** argv) {
    printf("%s version %s\n", name, version);
    puts("Press ctrl+c to exit\n");

    while (1) {
        // printf("")
        fputs(">> ", stdout);
        fgets(input, 2048, stdin);
        printf("Now you da %s", input);
    }

    return 0;
}
