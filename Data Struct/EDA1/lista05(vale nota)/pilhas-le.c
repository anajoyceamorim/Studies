#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
  int dado;
  struct celula *prox;
} celula;

void empilha (celula *p, int x) {
  celula *novo = (celula*) malloc(sizeof(celula));
  if (novo == NULL) return;

  novo->dado = x;
  novo->prox = p->prox;
  p->prox = novo;
}

int desempilha (celula *p, int *y) {
  if (p->prox == NULL) return 0;

  *y = p->prox->dado;

  celula *temp = p->prox;
  p->prox = p->prox->prox;

  free(temp);

  return 1;
}
