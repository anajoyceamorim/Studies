#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct stack {
    Node* top;
} stack;

stack* make_stack() {
    stack* sk = (stack*)malloc(sizeof(stack));
    sk->top = NULL;
    return sk;
}

bool empty(stack* sk) {
    return sk->top == NULL;
}

int top(stack* sk) {
    if (sk->top != NULL) {
        return sk->top->data;
    }
    return -1;
}

void pop(stack* sk) {
    if (sk->top != NULL) {
        Node* temp = sk->top;
        sk->top = sk->top->next;
        free(temp);
    }
}

void push(stack* sk, int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = sk->top;
    sk->top = new_node;
}

char* solve(int t) {
    int* cars = (int*)malloc(t * sizeof(int));
    int init = 1;
    for (int i = 0; i < t; i++) {
        scanf(" %d", &cars[i]);
    }

    stack* sk = make_stack();
    for (int i = 0; i < t; i++) {
        if (cars[i] == init) {
            init++;
        } else {
            while (!empty(sk) && top(sk) == init) {
                pop(sk);
                init++;
            }

            if (!empty(sk) && top(sk) < cars[i]) {
                free(cars);
                return "no";
            }
            push(sk, cars[i]);
        }
    }
    
    free(cars);
    return "yes";
}

int main() {
    int t;

    while (true) {
        scanf("%d", &t);
        if (t == 0) break;

        printf("%s\n", solve(t));
    }

    return 0;
}
