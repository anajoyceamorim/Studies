#include <stdio.h>
#include <stdlib.h>

#define MAX_PISTAS 5001

typedef struct Pista {
    int valor;
    int prox_id;
} Pista;

int main() {
    int n;
    scanf("%d", &n);

    Pista pistas[MAX_PISTAS];
    int start_id;

    for (int i = 0; i < MAX_PISTAS; i++) {
        pistas[i].prox_id = -2;
    }

    for (int i = 0; i < n; i++) {
        int id, valor, prox_id;
        scanf("%d %d %d", &id, &valor, &prox_id);
        pistas[id].valor = valor;
        pistas[id].prox_id = prox_id;
        if (i == 0) {
            start_id = id;
        }
    }

    int current_id = start_id;
    while (current_id != -1) {
        printf("%d\n", pistas[current_id].valor);
        current_id = pistas[current_id].prox_id;
    }

    return 0;
}