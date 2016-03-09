#include "stdio.h"

void myreverse(char s[], int start, int end) {
    char c;
    while (start <= end - 1) {
        c = s[start];
        s[start] = s[end - 1];
        s[end - 1] = c;
        start++;
        end--;
    }
}
