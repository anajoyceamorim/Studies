#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula* prox;
} celula;

int remove_depois(celula* p) {
    if (p == NULL || p->prox == NULL) return -1;
    int item = p->prox->dado;
    p->prox = p->prox->prox;
    return item;
}

void remove_elemento(celula* le, int x) {
    while (le->prox != NULL) {
        if (le->prox->dado == x) {
            le->prox = le->prox->prox;
            break;
        }
        le = le->prox;
    }
}

void remove_todos_elementos(celula* le, int x) {
    while (le->prox != NULL) {
        if (le->prox->dado == x) {
            le->prox = le->prox->prox;
        }
        else le = le->prox;
    }
}