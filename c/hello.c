#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
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
