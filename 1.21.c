#include "stdio.h"
#define MAXLEN 1000
#define TAB_WIDTH 8

int mygetline(char s[], int limit);

void echo_one_line(char s[]) {
    char c;
    int nb = 0;
    int nt = 0;
    int pos = 0;
    for (int si = 0; s[si] != '\0'; si++) {
        c = s[si];
        if (c == ' ') {
            if ((pos + 1) % TAB_WIDTH == 0) {
                nb = 0;
                nt++;
            } else {
                nb++;
            }
        } else {
            for (int i = 0; i < nt; i++) {
                putchar('\t');
                // printf("[TAB]\n");
            }
            nt = 0;

            if (c == '\t') {
                putchar('\t');
                // printf("[TAB]\n");
                nb = 0;
            } else {
                for (int i = 0; i < nb; i++) {
                    putchar(' ');
                    // printf("[BLK]\n");
                }
                nb = 0;
                putchar(c);
                // printf("%c\n", c);
            }

            if (c == '\t') {
                pos = pos + (TAB_WIDTH - (pos + 1) % TAB_WIDTH);
            }
        }
        pos++;
    }
}

int main() {
    char line[MAXLEN];
    int len;
    while((len = mygetline(line, MAXLEN)) > 0) {
        echo_one_line(line);
    }
}
