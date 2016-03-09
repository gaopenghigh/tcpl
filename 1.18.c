#include "stdio.h"

#define MAXLINE 1000

int mygetline(char s[], int limit);
int copy(char to[], char from[]);

int main() {
    int len;
    int i;
    char line[MAXLINE];
    char new_line[MAXLINE];

    while((len = mygetline(line, MAXLINE)) > 0) {
        copy(new_line, line);
        i = len - 2; // ends with \n
        while (i >= 0 && (new_line[i] == ' ' || new_line[i] == '\t')) {
            new_line[i] = '\0';
            i--;
        }
        if (i > 0) {
            new_line[i + 1] = '\n';
            printf("%s", new_line);
        }
    }
}
