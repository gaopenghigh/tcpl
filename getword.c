#include <stdio.h>
#include <ctype.h>

#define MAXLEN 1000

char getch();
void ungetch(char c);

int getword(char *word, int limit) {
    char *w = word;
    char c;
    while (isspace((c = getch()))) {
    }
    if (c != EOF) {
        *w = c;
        w++;
    }
    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }
    limit--;
    while (limit > 0) {
        c = getch();
        if (isalnum(c)) {
            *w = c;
            w++;
        } else {
            ungetch(c);
            break;
        }
        limit--;
    }
    *w = '\0';
    return w[0];
}
