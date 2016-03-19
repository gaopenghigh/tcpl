#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#define MAX_LEN 1000

int myatoi(char s[]);
int mygetline(char s[], int limit);

int main(int argc, char *argv[]) {
    int n = 10;
    while (argc > 1) {
        argv++;
        if (*argv[0] == '-') {
            n = myatoi(*argv + 1);
        }
        argc--;
    }
    printf("# n = %d\n", n);

    char line[MAX_LEN];
    int len;
    char *buf[n];
    int buf_pos = 0;
    char *p;
    while ((len = mygetline(line, MAX_LEN)) > 0) {
        p = malloc(len);
        strcpy(p, line);
        buf[buf_pos] = p;
        if (buf_pos >= n - 1) {
            buf_pos = 0;
        } else {
            buf_pos++;
        }
    }

    printf("# buf_pos = %d\n", buf_pos);
    int start = buf_pos;
    if (start >= n) {
        start = 0;
    }
    while (start < n) {
        printf("%s", buf[start]);
        start++;
    }

    for (int i = 0; i < buf_pos; i++) {
        printf("%s", buf[i]);
    }
}


