#include "stdio.h"

/* sort v[0] .. v[n-1] */
void shellsort(int v[], int n) {
    for (int gap=n/2; gap>0; gap/=2) {
        /* from left to right, sort all groups */
        for (int i=gap; i<n; i++) {
            /* find the right position */
            for (int j=i-gap; j>=0; j=j-gap) {
                if (v[j+gap] < v[j]) {
                    int t = v[j];
                    v[j] = v[j+gap];
                    v[j+gap] = t;
                }
            }
        }
    }
}

int main() {
    int v[] = {3,4,1,7,4,1,9,0,2,6};
    shellsort(v, 10);
    for (int i=0; i<10; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}
