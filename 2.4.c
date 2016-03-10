#include "stdio.h"
#define MAX_LEN 1000

void mysqueeze(char s[], char c) {
    int fast = 0;
    int slow = 0;
    while(s[fast] != '\0') {
        if (s[fast] != c) {
            s[slow] = s[fast];
            slow++;
        }
        fast++;
    }
    s[slow] = '\0';
}

void mysqueeze2(char s1[], char s2[]) {
    for (int i=0; s2[i] != '\0'; i++) {
        mysqueeze(s1, s2[i]);
    }
}

int main() {
    char s1[] = "abcdefghijk";
    char s2[] = "efg";
    printf("%s\n", s1);
    printf("%s\n", s2);
    mysqueeze2(s1, s2);
    printf("%s\n", s1);
}
