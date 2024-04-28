#include <stdio.h>

void regua01(int n);

void regua02(int p, int r, int h);

void traco(int m, int h);

int main() {

    int n;
    scanf("%d", &n);
    regua01(n);

    return 0;
}

void regua01(int n) {
    int i, pow = 1;
    for (i = 0; i < n; i++) {
        pow *= 2;
    }
    regua02(0, pow, n);
}

void regua02(int p, int r, int h) {
    int m = (p + r) / 2;
    if (h > 0) {
        regua02(p, m, h - 1);
        traco(m, h);
        regua02(m, r, h - 1);
    }
}

void traco(int m, int h) {
    printf(".");
    for (int i = 0; i < h; i++) {
        printf("-");
    }
    printf("\n");
}