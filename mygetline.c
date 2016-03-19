#include "stdio.h"

int mygetline(char s[], int limit) {
    int n = 0;
    char c;
    while((c = getchar()) != EOF && c != '\n' && n < limit - 1) {
        s[n] = c;
        n++;
    }
    if (c == '\n') {
        s[n] = c;
        n++;
    }
    s[n] = '\0';
    return n;
}
