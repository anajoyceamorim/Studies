#include <stdio.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void imprime (celula *le) 
{
    while(le->prox != NULL) //enquanto o meu prox ã apontar para NULL
    {
        le = le->prox; //eu ano na minha lista, ando desde do primeiro pq le é a cabeça
        printf("%d ->", le->dado); //imprimo meu dado
    }
    printf("NULL\n"); //encher linguiça da questão
}

void imprime_rec (celula *le)
{
    if(le->prox == NULL ) //condição de parada
    {
        printf("NULL\n");
        return;
    }
    printf("%d -> ", le->prox->dado); //aqui como eu não pulei a cabeça, já imprimo a partir da pros celula
    imprime_rec(le->prox); //chamo a minha função novamente
}
