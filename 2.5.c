#include "stdio.h"

int myany(char s1[], char s2[]) {
    for (int i=0; s1[i] != '\0'; i++) {
        for (int j=0; s2[j] != '\0'; j++) {
            if (s1[i] == s2[j]) {
                return i;
            }
        }
    }
    return -1;
}

int main() {
    char s1[] = "abcdefg";
    char s2[] = "egc";
    char s3[] = "x";
    printf("s1 = %s\n", s1);
    printf("s2 = %s\n", s2);
    printf("s3 = %s\n", s3);
    printf("%d\n", myany(s1, s2));
    printf("%d\n", myany(s1, s3));
}
