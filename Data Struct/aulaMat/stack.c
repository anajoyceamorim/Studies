#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int v;
    struct node* next;
} node;

node* make_stack()
{
    node* sk = (node*)malloc(sizeof(node));
    sk->next = NULL;
    return sk;
}

void push(node* sk, int x) {
    node* nm = make_stack();
    nm->v = x;
    nm->next = sk->next;
    sk->next = nm;
}

void pop(node* sk) {
    if(sk == NULL || sk->next == NULL) return;
    sk->next = sk->next->next;
}

/*
head -> 3 -> 5 -> 10 -> NULL
*/

int main() {

    node* start = make_stack();

    push(start, 10);
    push(start, 5);
    push(start, 3);

    printf("%d\n", start->next->v);
    printf("%d\n", start->next->next->v);
    printf("%d\n", start->next->next->next->v);

    pop(start);

    printf("\n%d\n", start->next->v);
    printf("%d\n", start->next->next->v);

    return 0;
}
