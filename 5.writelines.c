#include <stdio.h>

void writelines(char *lineptr[], int nlines) {
    for (int i=0; i<nlines; i++) {
        printf("%s", lineptr[i]);
    }
}
