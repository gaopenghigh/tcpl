#include "stdio.h"

void mystrcat(char s[], char t[]) {
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    for (int j = 0; t[j] != '\0'; j++) {
        s[i] = t[j];
        i++;
    }
    s[i] = '\0';
}

