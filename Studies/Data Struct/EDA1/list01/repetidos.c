#include <stdio.h>

int repetidos(int v[10000], int qtd, int index) {
    int num = v[index], equals = 0;
    for(int i = 0; i < qtd; i++){
        if(v[i] == num) {
            equals++;
        }
    }
    return equals - 1;
}

/*
int main () {
    
    //int v[10000] = {5, 2, 2, 3, 4, 4, 4, 4, 1, 1}, asw;
    //asw = repetidos(v, 10, 4);

    int v[10000] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0}, asw;
    asw = repetidos(v, 11, 10);

    printf("%d\n", asw);

    return 0;
}
*/