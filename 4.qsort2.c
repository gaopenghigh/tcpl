#include "stdio.h"

void swap(int v[], int i, int j) {
    int t = v[i];
    v[i] = v[j];
    v[j] = t;
}

void print_arr(int v[], int n) {
    for (int i=0; i<n; i++) {
        printf("%d, ", v[i]);
    }
    printf("\n");
}

void qsort(int v[], int l, int u) {
    if (l >= u) {
        return;
    }
    int i = l;
    int j = u;
    int pivot = v[l];
    while (i <= j) {
        while (v[i] < pivot) {
            i++;
        }
        while (v[j] > pivot) {
            j--;
        }
        if (i <= j) {
            swap(v, i, j);
            i++;
            j--;
        }
    }
    print_arr(v, 10);
    qsort(v, l, i - 1);
    qsort(v, i, u);
}


int main() {
    int v[] = {5,3,5,1,2,9,3,6,1,2};
    print_arr(v, 10);
    qsort(v, 0, 9);
    print_arr(v, 10);
}
