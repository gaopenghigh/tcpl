#include "stdio.h"
#define MAX_LEN 1000

void expand(char s1[], char s2[]) {
    int i = 0;
    int j = 0;
    while (s1[i] != '\0') {
        if (s1[i] == '-' && i - 1 >= 0 && s1[i+1] != '\0') {
            for (int t=1; t<(s1[i+1] - s1[i-1]); t++) {
                s2[j] = s1[i-1] + t;
                j++;
            }
        } else {
            s2[j] = s1[i];
            j++;
        }
        i++;
    }
}

int main() {
    char s1[] = "-zbbbba-ebbbba-z0-9a-z";
    char s2[MAX_LEN];
    printf("%s\n", s1);
    expand(s1, s2);
    printf("%s\n", s2);
}
