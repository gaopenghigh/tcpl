#include "stdio.h"
#define MAX_LEN 1000

double myatof(char s[]) {
    int power = 0;
    int flag = 0;
    int sign = 1;
    int sign_e = 1;

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
        power--;
    }

    if (s[i] == 'e' || s[i] == 'E') {
        i++;
        if (s[i] == '-') {
            sign_e = -1;
            i++;
        } else if (s[i] == '+') {
            i++;
        }
        int power_e = 0;
        while (s[i] >= '0' && s[i] <= '9') {
            power_e = power_e * 10 + s[i] - '0';
            i++;
        }
        power_e = power_e * sign_e;
        power = power + power_e;
    }

    printf("r=%f, power=%d\n", r, power);

    if (power > 0) {
        while (power > 0) {
            r = r * 10;
            power--;
        }
    } else if (power < 0) {
        while (power < 0) {
            r = r / 10;
            power++;
        }
    }
    return sign * r;
}

int main() {
    char s[] = "-01.2e-3";
    printf("%f\n", myatof(s));
}
