#include "stdio.h"
#define MAX_LEN 1000

void myreverse(char s[], int start, int end);

void myitoa(int n, char s[]) {
    int sign = 1;
    int j = 0;
    if (n < 0) {
        sign = -1;
        n = -n;
    }
    s[j] = (n % 10) + '0';
    j++;
    n = n / 10;
    while (n > 0) {
        printf("n=%d\n", n);
        s[j] = (n % 10) + '0';
        j++;
        n = n / 10;
    }
    if (sign < 0) {
        s[j] = '-';
        j++;
    }
    s[j] = '\0';
    myreverse(s, 0, j);
}

int main() {
    int n = 4210;
    char s[MAX_LEN];
    printf("%d\n", n);
    myitoa(n, s);
    printf("%s\n", s);
}
