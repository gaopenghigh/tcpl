#include "stdio.h"
#define MAX_LEN 1000

void myreverse(char s[], int start, int end) {
    if (start < end) {
        char c = s[start];
        s[start] = s[end];
        s[end] = c;
        myreverse(s, start+1, end-1);
    }
}

int main() {
    char s[] = "abcdefghig";
    myreverse(s, 0, 9);
    printf("%s\n", s);
}
