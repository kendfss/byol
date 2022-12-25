#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
    char* tests[] = {"", "1", "11", "111"};
    printf("'%s':\t%lu\n", tests[0], strlen(tests[0]));
    printf("'%s':\t%lu\n", tests[1], strlen(tests[1]));
    printf("'%s':\t%lu\n", tests[2], strlen(tests[2]));
    printf("'%s':\t%lu\n", tests[3], strlen(tests[3]));
    switch (argc) {
    case 0:
        puts("Hello, World!");
        return 1;
    default:
        for (int i = 1; i < argc; i++) {
            printf("Hello, %s!\n", argv[i]);
        }
        return 0;
    }
    return 13;
}
