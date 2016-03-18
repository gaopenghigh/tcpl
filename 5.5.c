#include <stdio.h>
#define MAX_LEN 1000

void mystrncpy(char *s, char *t, int n) {
    char *pt = t;
    while (*pt != '\0' && pt < t + n) {
        *s = *pt;
        pt++;
        s++;
    }
}

void mystrncat(char *s, char *t, int n) {
    while (*s != '\0') {
        s++;
    }
    char *pt = t;
    while (pt < t + n && *pt != '\0') {
        *s = *pt;
        pt++;
        s++;
    }
    *s = '\0';
}

int mystrncmp(char *s, char *t, int n) {
    char *pt = t;
    while (pt < t + n && *pt != '\0' && *s != '\0' && *pt == *s) {
        pt++;
        s++;
    }
    if (pt == t + n) {
        return 0;
    }
    return *s - *pt;
}

int main() {
    char s1[MAX_LEN] = "abcdefg";
    char *t1 = "xxx";
    mystrncpy(s1, t1, 2);
    printf("%s\n", s1);
    printf("----\n");

    char s3[MAX_LEN] = "abcd";
    char *t3 = "efg";
    mystrncat(s3, t3, 3);
    printf("%s\n", s3);
    char s4[MAX_LEN] = "abcd";
    char *t4 = "efg";
    mystrncat(s4, t4, 1);
    printf("%s\n", s4);
    printf("----\n");

    char s5[MAX_LEN] = "abcdef";
    char *t5 = "abca";
    printf("%d\n", mystrncmp(s5, t5, 4));
}

