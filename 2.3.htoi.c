#include "stdio.h"
#define MAX_LEN 1000

int myhtoi(char s[]) {
    int r = 0;
    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) {
        for (int i = 2; s[i] != '\0'; i++) {
            if ('0' <= s[i] && s[i] <= '9') {
                r = r * 16 + (s[i] - '0');
            } else if ('A' <= s[i] && s[i] <= 'F') {
                r = r * 16 + (10 + s[i] - 'A');
            } else if ('a' <= s[i] && s[i] <= 'f') {
                r = r * 16 + (10 + s[i] - 'a');
            } else {
                break;
            }
        }
    }
    return r;
}

int main() {
    char s[MAX_LEN];
    char c;
    int i = 0;
    while((c = getchar()) != EOF) {
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    printf("%d\n", myhtoi(s));
}
