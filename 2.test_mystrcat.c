#include "stdio.h"
#include "2.mystrcat.c"
#include "mygetline.c"

#define MAX_LEN 1000

int main() {
    char s[MAX_LEN];
    char t[MAX_LEN];
    mygetline(s, MAX_LEN);
    mygetline(t, MAX_LEN);
    mystrcat(s, t);
    printf("%s\n", s);
}


