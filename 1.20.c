#include "stdio.h"

#define MAXLINE 1000
#define TABWIDTH 4

int mygetline(char s[], int limit);

void detab(char s[], int len) {
    int nb = 0; // number of blanks
    for (int i = 0; i < len; i++) {
        if (s[i] == '\t') {
            nb = TABWIDTH - i % TABWIDTH;
            for (int j = 0; j < nb; j++) {
                putchar(' ');
            }
        } else {
            putchar(s[i]);
        }
    }
}

int main() {
    int len;
    int i;
    char line[MAXLINE];

    while((len = mygetline(line, MAXLINE)) > 0) {
        detab(line, len);
    }
}

