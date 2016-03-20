#include <stdio.h>
#include <string.h>

#define MAX_LINES 1000

int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int nlines);

void swap(void *v[], int i, int j) {
    void *t = v[i];
    v[i] = v[j];
    v[j] = t;
}

void qsort(void *lineptr[], int left, int right, int (*cmp)(void *, void *)) {
    if (left >= right) {
        return;
    }
    void *pivot = lineptr[left];
    int slow = left;
    for (int fast = left + 1; fast <= right; fast++) {
        if ((*cmp)(lineptr[fast], pivot) < 0) {
            slow++;
            swap(lineptr, slow, fast);
        }
    }
    swap(lineptr, left, slow);
    qsort(lineptr, left, slow-1, cmp);
    qsort(lineptr, slow+1, right, cmp);
}

int main() {
    char *lineptr[MAX_LINES];
    int nlines = readlines(lineptr, MAX_LINES);
    int (*cmp)(void *, void *) = (int (*)(void *, void *))strcmp;
    qsort((void **)lineptr, 0, nlines - 1, cmp);
    writelines(lineptr, nlines);
}
