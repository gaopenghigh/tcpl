#include <stdio.h>
#define MAX_LEN 1000

int mystrlen(char *s) {
    char *t = s;
    while (*s != '\0') {
        s++;
    }
    return s - t;
}

int strend(char *s, char *t) {
    int sl = mystrlen(s);
    int tl = mystrlen(t);
    char *ps = s + sl - 1;
    char *pt = t + tl - 1;
    while (pt - t >= 0 && *pt == *ps) {
        if (pt - t == 0) {
            return 1;
        }
        pt--;
        ps--;
    }
    return 0;
}

int main() {
    char *s = "abcdefg";
    char *t1 = "efgh";
    char *t2 = "fg";
    printf("%d\n", mystrlen(s));
    printf("%d\n", strend(s, t1));
    printf("%d\n", strend(s, t2));
}
