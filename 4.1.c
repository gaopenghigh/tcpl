#include "stdio.h"
#define MAX_LEN 1000

int mystrlen(char s[]) {
    int l = 0;
    while (s[l] != '\0') {
        l++;
    }
    return l;
}

int strindex(char s[], char t[]) {
    int s_len = mystrlen(s);
    int t_len = mystrlen(t);

    for (int index = s_len - 1; index >= 0; index--) {
        int i = index;
        int j = t_len - 1;
        while (j >= 0) {
            if (s[i] == t[j]) {
                if (j == 0) {
                    return i;
                }
                i--;
                j--;
            } else {
                break;
            }
        }
    }
    return -1;
}

int main() {
    char s[] = "abcdefgcdefe";
    char t[] = "cde";
    printf("s: %s : %d\n", s, mystrlen(s));
    printf("t: %s : %d\n", t, mystrlen(t));
    printf("%d\n", strindex(s, t));
}
