#include "stdio.h"

int binsearch(int v[], int x, int n) {
    int low = 0;
    int high = n - 1;
    int mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (v[mid] < x) {
            low = mid + 1;
        } else if (v[mid] > x) {
            high = mid - 1;
        } else {
            return mid;
        }
    }
    return -1;
}

int binsearch2(int v[], int x, int start, int end) {
    if (start > end) {
        return -1;
    }
    int mid = (start + end) / 2;
    if (v[mid] < x) {
        return binsearch2(v, x, mid + 1, end);
    } else if (v[mid] > x) {
        return binsearch2(v, x, start, mid - 1);
    } else {
        return mid;
    }
}

int main() {
    int v[] = {1, 2, 3, 4, 5, 6};
    printf("%d\n", binsearch(v, 4, 6));
    printf("%d\n", binsearch(v, 0, 6));
    printf("%d\n", binsearch2(v, 4, 0, 5));
    printf("%d\n", binsearch2(v, 0, 0, 5));
}
