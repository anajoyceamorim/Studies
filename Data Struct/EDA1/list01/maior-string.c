#include <stdio.h>
#include <string.h>

#define MAX 1012

int main() {

    char string[MAX];
    int n, tam = 0, j;

    scanf("%d", &n);

    for (int i = 0; i <= n; i++) {
        fgets(string, sizeof(string), stdin);
        j = 0;
        while(string[j] != '\0') {
            j++;
        }
        if(j > tam){
            tam = j;
        }
    } 

    printf("%d\n", tam - 1);

    return 0;
}