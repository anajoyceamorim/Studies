#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

//funções para impressão
void imprime (celula *le);
void imprime_rec (celula *le);

//funções para inserção
void insere_inicio (celula *le, int x); //insere no inicio da le
void insere_antes (celula *le, int x, int y); //insere x antes de y

//função para procurar um elem. Retorna um ponteiro p/ o elem
celula *busca (celula *le, int x);
celula *busca_rec (celula *le, int x);

//funçoes para remover um elemento
int remove_depois (celula *p);
void remove_elemento (celula *le, int x);
void remove_todos_elementos (celula *le, int x);

int main (){
    //inicializando a cabeça le
    celula *le = malloc(sizeof(celula));
    le->prox = NULL;  

    insere_inicio(le, 2);
    insere_antes(le, 4, 2);

    printf("%p \n", busca(le, 2));
    printf("%p \n", busca_rec(le, 2));

    imprime(le);
    imprime_rec(le);

    free(le);  
    return 0;
}

void imprime (celula *le) 
{
    while( le->prox != NULL)
    {
        le = le->prox;
        printf("%d -> ", le->dado);
    }
    printf("NULL\n");
}

void imprime_rec (celula *le)
{
    if (le->prox == NULL) {
        printf("NULL\n");
        return;
    }
    printf("%d -> ", le->prox->dado);
    imprime_rec(le->prox);
}

void insere_inicio (celula *le, int x)
{
    celula* nova = malloc(sizeof(celula));
    nova->dado = x; 
    nova->prox = le->prox; 
    le->prox = nova; 
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

celula *busca (celula *le, int x)
{
    while (le->prox != NULL)
    {
        le = le->prox;
        if (le->dado == x)
        return le;
    }
    return NULL;
}

celula *busca_rec (celula *le, int x)
{
    if (le->prox == NULL) 
    return NULL;
    if (le->prox->dado == x)
    return le->prox;
    busca_rec(le->prox, x);
}

int remove_depois (celula *p)
{
    if (p == NULL || p->prox == NULL) return -1;
    int item = p->prox->dado;
    p->prox = p->prox->prox;
    return item;
}
void remove_elemento (celula *le, int x)
{

}
void remove_todos_elementos (celula *le, int x)
{

}