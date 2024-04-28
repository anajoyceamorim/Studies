#include <stdio.h>

void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

/*
int main() {

    int a, b;

    scanf("%d%d", &a, &b);

    printf("Antes: %d %d\n", a, b);
    swap(&a, &b);
    printf("Depois: %d %d\n", a, b);

    return 0;
}
*/
