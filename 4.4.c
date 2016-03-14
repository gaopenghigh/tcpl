#include "stdio.h"
#define STACK_LEN 1000

double val[STACK_LEN];
int sp = 0;

void push(double f) {
    if (sp >= STACK_LEN) {
        printf("stack is full\n");
    } else {
        val[sp] = f;
        sp++;
    }
}

double pop() {
    if (sp == 0) {
        printf("stack is empty\n");
        return 0.0;
    }
    sp--;
    return val[sp];
}

double pick() {
    if (sp == 0) {
        printf("stack is empty\n");
        return 0.0;
    }
    return val[sp-1];
}

void clean() {
    sp = 0;
}

int main() {
    push(5.4);
    push(3.2);
    push(782);
    printf("pop: %f\n", pop());
    printf("pick: %f\n", pick());
    printf("pop: %f\n", pop());
    printf("pop: %f\n", pop());
    printf("pop: %f\n", pop());
}
