#include <stdio.h>

#define MAX 1012345

int main() {

    int vet[MAX], num, n;

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &vet[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        vet[i] += num;
    }

    for(int i = 0; i < n; i++) {
        printf("%d ", vet[i]);
    }
    
    printf("\n");

    return 0;
}