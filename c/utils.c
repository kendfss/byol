#pragma once

#include <stdarg.h> // va_*
#include <stdio.h>
#include <stdlib.h> // calloc
#include <string.h> // strlen, strcpy

#include "../../../donmccaughey/va_args_count/va_args_count.h"

char* clone(char* s1) {
    int len = strlen(s1);
    char* out = malloc(len + 1);
    int ctr = 0;
    int shift = 0;
    int delta = sizeof(char);
    char* p = s1;
    while (*p) {
        shift = ctr * delta;
        *(out + shift) = *p;
        ctr++;
        p += delta;
    }
    return out;
}

int totalLength(char* parts[], int count) {
    int out = 0;
    for (int i = 0; i < count; i++) {
        int part = strlen(parts[i]);
        out += part;
    }

    return out;
}

char* join(char* sep, char* parts[], int count) {
    int len = totalLength(parts, count) + (strlen(sep) * (count - 1));
    char* out = calloc(len, sizeof(char));

    for (int i = 0; i < count; i++) {
        out = strcat(out, parts[i]);
        out = strcat(out, sep);
    }
    return out;
}
