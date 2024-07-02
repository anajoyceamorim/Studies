#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct stack {
    int data;
    struct stack* next;
} stack;

stack* make_stack() {
    stack* sk = (stack*)malloc(sizeof(stack));
    sk->next = NULL;
    return sk;
}

bool empty(stack* p) {
    return p == NULL || p->next == NULL;
}

void push(stack* p, int x) {
    stack* sk = (stack*)malloc(sizeof(stack));
    sk->data = x;
    sk->next = p->next;
    p->next = sk;
}

void pop(stack* p) {
    stack* trash = p->next;
    p->next = p->next->next;
    free(trash);
}

int top(stack* p) {
    stack* top = p->next;
    return top->data;
}

char string[100007];
char expressoes() {
    scanf("%s", string);

    stack* sk = make_stack();
    int len = strlen(string);
    for (int i = 0; i < len; i++) {
        if (string[i] == '[' || string[i] == '{' || string[i] == '(') push(sk, string[i]);
        else {
            if (!empty(sk)) {
                int y = top(sk);
                pop(sk);

                if (y != string[i] - 1 && y != string[i] - 2) return 'N';
            } else return 'N';
        }
    }

    if (!empty(sk)) return 'N';
    else return 'S';
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        printf("%c\n", expressoes());
    }

    return 0;
}