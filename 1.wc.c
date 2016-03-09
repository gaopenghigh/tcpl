#include "stdio.h"

#define STAT_IN 0
#define STAT_OUT 1

int main() {
    int cc = 0, wc = 0, lc = 0;
    int stat = STAT_IN;
    char c;
    while ((c = getchar()) != EOF) {
        if (c != '\n' && c != ' ' && c != '\t') {
            cc++;
        }
        if (c == '\n') {
            lc++;
            wc++;
        }
        if (c == ' ' && stat == STAT_IN) {
            wc++;
            stat = STAT_OUT;
        }
        if (c != ' ' && stat == STAT_OUT) {
            stat = STAT_IN;
        }
    }
    printf("cc=%d, wc=%d, lc=%d\n", cc, wc, lc);
}
