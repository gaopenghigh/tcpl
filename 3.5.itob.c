#include "stdio.h"
#define MAX_LEN 1000

void myreverse(char s[], int start, int end);

void myitob(int n, char s[], int b) {
    int t;
    int j = 0;
    int sign = 1;
    if (n < 0) {
        sign = -1;
        n = -n;
    }
    do {
        t = n % b;
        if (t <= 9) {
            s[j] = '0' + t;
            j++;
        } else {
            s[j] = 'A' + t - 10;
            j++;
        }
        n = n / b;
    } while (n > 0);
    if (sign < 0) {
        s[j] = '-';
        j++;
    }
    s[j] = '\0';
    myreverse(s, 0, j);
}

int main() {
    int n = 255;
    char s[MAX_LEN];
    printf("%d\n", n);
    myitob(n, s, 16);
    printf("%s\n", s);
}
