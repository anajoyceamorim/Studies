#include <stdio.h>

int piramide_2 (int num) {
    for (int i = 1; i <= num; i++) {
        for (int j = 1; j <= num - i; j++) {
            printf(" ");
        }
        for (int k = 1; k <= 2 * i - 1; k++){
            printf("*");
        }
        printf("\n");
    }
}

int main(){
    int num;

    scanf("%d", &num);
    piramide_2(num);

    return 0;
}