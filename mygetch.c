#include <stdio.h>
#define BUFSIZE 1000

static char buf[BUFSIZE];
static int bp = 0;

char getch() {
    if (bp > 0) {
        char c = buf[bp-1];
        bp--;
        return c;
    }
    return getchar();
}

void ungetch(char c) {
    if (bp >= BUFSIZE) {
        printf("buf full\n");
        return;
    }
    buf[bp] = c;
    bp++;
}
