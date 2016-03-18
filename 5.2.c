#include <stdio.h>
#include <ctype.h>

char getch();
void ungetch(char c);

int getfloat(float *pf) {
    int c;
    int sign = 1;
    int power = 0;

    while (isspace((c = getch()))) {
        ;
    }
    if (c == '-') {
        sign = -1;
    }
    if (c == '-' || c == '+') {
        c = getch();
    }

    *pf = 0.0;
    while(isdigit(c)) {
        *pf = *pf * 10 + c - '0';
        c = getch();
        printf("debug %f\n", *pf);
    }
    if (c == '.') {
        c = getch();
    }
    while(isdigit(c)) {
        *pf = *pf * 10 + c - '0';
        power++;
        c = getch();
    }
    while (power > 0) {
        *pf = *pf / 10;
        power--;
    }
    if (c != EOF) {
        ungetch(c);
    }
    return c;
}

int main() {
    float f;
    printf("%d\n", getfloat(&f));
    printf("%f\n", f);
}
