#include "stdio.h"
#define MAX_LEN 1000

void myitoa(int n, char s[]) {
    static int i;
    printf("n=%d, s=%s\n", n, s);
    if (n >= 10) {
        myitoa(n/10, s);
    } else {
        i = 0;
        if (n < 0) {
            s[i] = '-';
            i++;
        }
    }
    s[i] = n % 10 + '0';
    i++;
    s[i] = '\0';
}

int main() {
    int i = 12345;
    char s[MAX_LEN];
    myitoa(i, s);
    printf("%s\n", s);
}
