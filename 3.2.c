#include "stdio.h"
#define MAX_LEN 1000

void escape(char s[], char t[]) {
    int j = 0;
    for (int i=0; t[i] != '\0'; i++) {
        switch (t[i]) {
            case '\t':
                  s[j] = '\\';
                  j++;
                  s[j] = 't';
                  break;
            case '\n':
                  s[j] = '\\';
                  j++;
                  s[j] = 'n';
                  break;
            default:
                  s[j] = t[i];
        }
        j++;
    }
}

void unescape(char s[], char t[]) {
    int j = 0;
    for (int i=0; t[i] != '\0'; i++) {
        if (t[i] == '\\' && t[i+1] != '\0') {
            switch (t[i+1]) {
                case 't':
                    s[j] = '\t';
                    j++;
                    i++;
                    break;
                case 'n':
                    s[j] = '\n';
                    j++;
                    i++;
                    break;
                default:
                    s[j] = t[i];
                    j++;
                    break;
            }
        } else {
            s[j] = t[i];
            j++;
        }
    }
}

int main() {
    char s[MAX_LEN];
    char s2[MAX_LEN];
    char t[] = "abc\td\\mef\tghi\njkl\n";
    printf("%s\n", t);
    escape(s, t);
    printf("%s\n", s);
    unescape(s2, s);
    printf("%s\n", s2);
}
