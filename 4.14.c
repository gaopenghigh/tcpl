#include <stdio.h>

#define swap(t, x, y) { \
    t _t; \
    _t = x; \
    x = y; \
    y = _t;}

int main() {
    int i = 1;
    int j = 2;
    swap(int, i, j);
    printf("%d, %d\n", i, j);
}

