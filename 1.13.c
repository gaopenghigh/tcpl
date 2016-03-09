#include "stdio.h"

#define STAT_IN 0 
#define STAT_OUT 1 
#define MAX_WORD_LEN 15
#define MAX_HIST_LEN 30

int main() {
    int wl[MAX_WORD_LEN];
    int over_flow = 0;
    int stat = STAT_OUT;
    
    // init
    for (int i = 0; i < MAX_WORD_LEN; i++) {
        wl[i] = 0;
    }

    // calculate
    int nc = 0;
    char c;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (stat == STAT_IN) {
                if (nc > MAX_WORD_LEN) {
                    over_flow++;
                } else {
                    wl[nc] = wl[nc] + 1;
                }
            }
            stat = STAT_OUT;
            nc = 0;
        } else if (stat == STAT_OUT) {
            nc = 1;
            stat = STAT_IN;
        } else {
            nc++;
        }
    }

    // calculate max_word_len
    int max_word_len = 0;
    for (int i = 0; i < MAX_WORD_LEN; i++) {
        if (max_word_len < wl[i]) {
            max_word_len = wl[i];
        }
    }

    // print horizontal histogram
    int nstar = 0;
    for (int l = 1; l <= MAX_WORD_LEN; l++) {
        printf(" %5d:%5d ", l, wl[l-1]);
        nstar = wl[l-1] * MAX_HIST_LEN / max_word_len;
        for (int i = 0; i < nstar && i < MAX_HIST_LEN; i++) {
            printf("*");
        }
        printf("\n");
    }
    if (over_flow > 0) {
        printf(">%5d:%5d ", MAX_WORD_LEN, over_flow);
        nstar = over_flow / max_word_len * MAX_HIST_LEN;
        for (int i = 0; i < nstar && i < MAX_HIST_LEN; i++) {
            printf("*");
        }
        printf("\n");
    }

    printf("\n"); 

    // print vertical histogram
    for (int r = MAX_HIST_LEN; r >= 0; r--) {
        for (int l = 0; l < MAX_WORD_LEN; l++) {
            if (wl[l] * MAX_HIST_LEN > max_word_len * r) {
                printf(" * ");
            } else {
                printf("   ");
            }
        }
        printf("\n");
    }
    for (int l = 0; l < MAX_WORD_LEN; l++) {
        printf("%3d", wl[l]);
    }
    printf("\n");
    for (int l = 0; l < MAX_WORD_LEN; l++) {
        printf("%3d", l);
    }
    printf("\n");
}

