#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
int dado;
struct celula *prox;
} celula;

void imprime (celula *le);

celula *enfileira (celula *f, int x);
int desenfileira (celula *f, int *y);

int main() {
    celula *head = malloc(sizeof(celula));
    head->prox = NULL;
    head->dado = 0;

    celula *fn = enfileira(head, 1);
    fn = enfileira(fn, 2);
    imprime(head);

    int y;
    desenfileira(head, &y);
    printf("%d \n", y);
    imprime(head);

    return 0;
}

void imprime (celula *f) 
{
    while( f->prox != NULL)
    {
        printf("%d -> ", f->dado);
        f = f->prox;
    }
    printf("NULL\n");
}

celula *enfileira (celula *f, int x)
{
    celula *nova = malloc(sizeof(celula));
    if (nova == NULL) return NULL;

    nova->prox = f->prox;
    f->prox = nova;
    f->dado = x;

    return nova;
}

int desenfileira (celula* f, int* y)
{
    if (f == NULL || f->prox == NULL ) return 0;

    celula* lixo = f->prox;

    *y = f->prox->dado;
    f->prox = f->prox->prox;

    free(lixo);
    return 1;
}