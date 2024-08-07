#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct queue {
    int data;
    struct queue* next;
} queue;

queue* make_queue() {
    queue* qs = (queue*)malloc(sizeof(queue));
    qs->next = NULL;
    return qs;
}

bool empty(queue* f) {
    return f == NULL || f->next == NULL;
}

queue* push(queue* f, int x) {
    queue* node = (queue*)make_queue();
    node->next = f->next;
    f->next = node;
    f->data = x;
    return node;
}

void pop(queue* f) {
    f->next = f->next->next;
}

queue* front(queue* f) {
    return f->next;
}

int vivo_ou_morto(int p, int r) {
    int m, n, j;

    queue* start = make_queue();
    queue* head = make_queue();
    start->next = head;
    queue* curr = head;
    for (int i = 0; i < p; i++) {
        scanf(" %d", &m);
        curr = push(curr, m);
    }

    for (int i = 0; i < r; i++) {
        int tmp = 0;
        scanf("%d %d", &n, &j);
        for (int k = 0; k < n; k++) {
            scanf(" %d", &m);
            if (m != j) {
                curr = start;
                for (int l = 0; l < k - tmp; l++) curr = curr->next;
                curr->next = curr->next->next;
                tmp++;
            }
        }
    }

    return front(start)->data;
}


int main() {

    int p, r, t = 1;

    while (true) {
        scanf("%d %d", &p, &r);
        if (p == 0 && r == 0) break;

        printf("Teste %d\n", t++);
        printf("%d\n", vivo_ou_morto(p, r));
    }

    return 0;
}
