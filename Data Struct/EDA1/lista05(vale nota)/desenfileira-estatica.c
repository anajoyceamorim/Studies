#include <stdio.h>
#include <stdlib.h>

typedef struct fila {
    int *dados;
    int N, p, u;
}fila;

int desenfileira (fila *f, int *y) {
    if (f->p == f->u) {
        return 0;
    }

    *y = f->dados[f->p];
    f->p++;

    if (f->p == f->N) {
        int *newData = (int*) realloc(f->dados, 2 * f->N * sizeof(int));
        if (newData == NULL) {
            return 0;
        }
        f->dados = newData;
        f->N *=2;
    }
    return 1;
}
