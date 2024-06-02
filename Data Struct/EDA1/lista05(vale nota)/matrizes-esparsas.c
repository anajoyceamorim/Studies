#include <stdio.h>
#include <stdlib.h>

/*
IDEIA: a ideia é ter um vetor com ponteiros, cada slot aponta para uma linha da matriz
m = quant de linhas
*/

typedef struct matrizLinha {

} matrizLinha;

matrizlinha* make_node(matrizLinha* node);

int main(){

    return 0;
}

matrizLinha* make_node(matrizLinha* node, int x)
{
    matrizLinha* nova = malloc(sizeof(matrizLinha));
    if(nova == NULL) return NULL;
}
