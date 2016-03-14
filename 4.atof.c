#include "stdio.h"
#define MAX_LEN 1000

double myatof(char s[]) {
    int power = 0;
    int flag = 0;
    int sign = 1;

    int i = 0;
    while (s[i] == ' ' || s[i] == '\t') {
        i++;
    }

    if (s[i] == '-') {
        sign = -1;
        i++;
    } else if (s[i] == '+') {
        sign = 1;
        i++;
    }

    double r = 0.0;
    while (s[i] != '\0' && s[i] >= '0' && s[i] <= '9') {
        r = r * 10 + s[i] - '0';
        i++;
    }

    if (s[i] == '.') {
        i++;
    }

    while (s[i] != '\0' && s[i] >= '0' && s[i] <= '9') {
        r = r * 10 + s[i] - '0';
        i++;
        power++;
    }
    while (power > 0) {
        r = r / 10;
        power--;
    }

    return r * sign;
}

int main() {
    char s[] = "-01.2332.";
    printf("%f\n", myatof(s));
}
