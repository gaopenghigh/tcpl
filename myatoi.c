#include "stdio.h"
#include "ctype.h"

#define MAX_LEN 1000

int myatoi(char s[]) {
    int r = 0;
    int i = 0;
    int sign = 1;
    while (isspace(s[i])) {
        i++;
    }
    if (s[i] == '-') {
        sign = -1;
        i++;
    } else if (s[i] == '+') {
        i++;
    }
    while(s[i] != '\0' && isdigit(s[i])) {
        r = 10 * r + (s[i] - '0');
        i++;
    }
    return r * sign;
}
