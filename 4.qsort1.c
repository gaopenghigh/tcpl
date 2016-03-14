#include "stdio.h"

void swap(int v[], int i, int j) {
    int t = v[i];
    v[i] = v[j];
    v[j] = t;
}

void qsort(int v[], int l, int u) {
    if (l >= u) {
        return;
    }
    int slow = l;
    int fast = l + 1;
    int m = v[slow];
    while (fast <= u) {
        if (v[fast] <= m) {
            slow++;
            swap(v, slow, fast);
        }
        fast++;
    }
    swap(v, l, slow);
    qsort(v, l, slow-1);
    qsort(v, slow+1, u);
}

void print_arr(int v[], int n) {
    for (int i=0; i<n; i++) {
        printf("%d, ", v[i]);
    }
    printf("\n");
}

int main() {
    int v[] = {0,3,7,1,2,9,3,6,1,2};
    print_arr(v, 10);
    qsort(v, 0, 9);
    print_arr(v, 10);
}
