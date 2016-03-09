#include "stdio.h"
#define STAT_IN 0
#define STAT_OUT 1

int main() {
    int stat = STAT_OUT;
    char c;
    while((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (stat == STAT_IN) {
                putchar('\n');
            }
            stat = STAT_OUT;
        } else {
            putchar(c);
            stat = STAT_IN;
        }
    }
}
