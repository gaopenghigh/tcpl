#include "stdio.h"

#define MAXLINE 1000

int mygetline(char s[], int limit);
int myreverse(char s[], int start, int end);

int main() {
    int len;
    int i;
    char line[MAXLINE];

    while((len = mygetline(line, MAXLINE)) > 0) {
        myreverse(line, 0, len - 1); // do not reverse \n
        printf("%s", line);
    }
}
