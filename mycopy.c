#include "stdio.h"

int copy(char to[], char from[]) {
    char c;
    int n = 0;
    while ((to[n] = from[n]) != '\0') {
        n++;
    }
    return n;
}
