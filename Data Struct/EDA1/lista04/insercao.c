#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void insere_inicio (celula *le, int x)
{
    celula *nova = malloc(sizeof(celula)); //aloco espaço p/ a minha nova celula
    nova->dado = x; //faço a minha nova celula receber o dado
    nova->prox = le->prox; //minha nova recebe o endereço da próxima celula
    le->prox = nova; //minha celula anterior recebe o endereço da minha celula atual
}

void insere_antes (celula *le, int x, int y)
{
    celula *nova = malloc(sizeof(celula)), *aux;
    nova->dado = x;

    while(le->prox != NULL)
    {
        aux = le; //recebe minha cabeça
        le = le->prox; //atualiza p/ minha prox celula
        if(le->dado == y) //se o dado for igual a y
        {
            nova->prox = le; //nova celula prox aponta p/ o prox endereço 
            aux->prox = nova; //celula anterior recebe o endereço da celula atual
            return;
        }
    }
    le->prox = nova; //atuliza a cabeça
    nova->prox = NULL; //prox da celula aponta para NULL
}
