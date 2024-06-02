#include <stdio.h>
#include <stdlib.h>

typedef struct pilha{
    int *v;
    int N;
    int topo;
} pilha;

void redimenciona(pilha* p) 
{
    int N = 2 * p->N;
    int* v = malloc(N * sizeof(int));

    for (int i = 0; i < p->topo; i++)
        v[i] = p->v[i];
    p->N = N;

    free(p->v);
    p->v = v;
}

void empilha (pilha *v, int x){
    if(v->topo == v->N) redimenciona(v);

    v->v[v->topo++] = x;
}

int desempilha (pilha *p, int *y){
    if (p == NULL || p->topo == 0) 
    return 0;

    *y = p->v[--p->topo];
    return 1;
}