#include <stdio.h>

#define MAX 1012345

int main() {

    int vet[MAX], n, num;

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &vet[i]);
    }

    scanf("%d", &num);

    for (int i = 0; i < n; i++) {
        if (vet[i] == num) {
            printf("pertence\n");
            return 0;
        }
    }
    
    printf("nao pertence\n");

    return 0;
}