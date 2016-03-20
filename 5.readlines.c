#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1000

int mygetline(char s[], int limit);

int readlines(char *lineptr[], int maxlines) {
    char line[MAX_LINE_LEN];
    int n_lines = 0;
    int len = 0;
    char *p;
    while ((len = mygetline(line, MAX_LINE_LEN)) > 0) {
        p = malloc(len);
        strcpy(p, line);
        lineptr[n_lines] = p;
        n_lines++;
    }
    return n_lines;
}
