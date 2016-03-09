#include "stdio.h"

void read_comment(char c);
void echo_quote(char c);
void in_comment();

int main() {
    char c;
    while((c = getchar()) != EOF) {
        read_comment(c);
    }
    return 0;
}

void read_comment(char c) {
    char d;
    if (c == '/') {
        d = getchar();
        if (d == '/') {
            putchar(c);
            read_comment(d);
        } else if (d == '*') {
            in_comment();
        } else {
            putchar(c);
            putchar(d);
        }
    } else if (c == '"' || c == '\'') {
        echo_quote(c);
    } else {
        putchar(c);
    }
}

void in_comment() {
    char c;
    char d;
    while((c = getchar()) != EOF) {
        if (c == '*') {
            if ((d = getchar()) == '/') {
                break;
            }
        }
    }
}

void echo_quote(char c) {
    char d;
    putchar(c);
    while((d = getchar()) != EOF) {
        if (d == c) {
            putchar(d);
            return;
        } else if (d == '\\') {
            putchar(d);
            putchar(getchar());
        } else {
            putchar(d);
        }
    }
}
