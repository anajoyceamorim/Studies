#include <stdio.h>

void imprime(int m, int h) {
    printf(".");
    for (int i = 0; i < h; i++) {
        printf("-");
    }
    printf("\n");
}

void reguaInglesa(int p, int r, int h) {
    int m = (p + r) / 2;
    if (h > 0) {
        reguaInglesa(p, m, h - 1);
        imprime(m, h);
        reguaInglesa(m, r, h - 1);
    }
}

void regua(int n) {
    int i, pot = 1;
    for (i = 0; i < n; i++)
        pot *= 2;
    reguaInglesa(0, pot, n);
}

int main() {
    int n;
    scanf("%d", &n);
    regua(n);
    return 0;
}
