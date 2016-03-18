#include <stdio.h>
#define MAX_LEN 1000

void mystrcat(char *s, char *t) {
    while (*s != '\0') {
        s++;
    }
    while ((*s = *t) != '\0') {
        s++;
        t++;
    }
    *s = '\0';
}

int main() {
    char s[MAX_LEN] = "abcd";
    char *t = "efg";
    mystrcat(s, t);
    printf("%s\n", s);
}
