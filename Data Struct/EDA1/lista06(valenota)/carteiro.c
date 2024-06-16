#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int valor;
    int index;
    struct No *esq;
    struct No *dir;
} No;

No *novo(int valor, int index)
{
    No *novoNo = malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->index = index;
    novoNo->esq = NULL;
    novoNo->dir = NULL;

    return novoNo;
}

No *inserir(No *raiz, int valor, int index)
{
    if (raiz == NULL)
        return novo(valor, index);

    if (valor < raiz->valor)
        raiz->esq = inserir(raiz->esq, valor, index);
    else
        raiz->dir = inserir(raiz->dir, valor, index);

    return raiz;
}

int buscaNo(No *raiz, int valor)
{
    if (raiz == NULL)
        return -1;

    if (valor == raiz->valor)
        return raiz->index;

    if (valor < raiz->valor)
        return buscaNo(raiz->esq, valor);
    else
        return buscaNo(raiz->dir, valor);
}

int main()
{
    No *raiz = NULL;
    int N, M, enderecos, encomendas;
    int total = 0, posicAtual = 0, posicAnterior = 0;

    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &enderecos);
        raiz = inserir(raiz, enderecos, i);
    }

    for (int j = 0; j < M; j++)
    {
        scanf("%d", &encomendas);
        posicAtual = buscaNo(raiz, encomendas);
        total += abs(posicAtual - posicAnterior);
        posicAnterior = posicAtual;
    }

    printf("%d", total);
}