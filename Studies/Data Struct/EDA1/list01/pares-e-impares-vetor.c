#include <stdio.h>

#define MAX 1012345

int main() {

    int vet_even[MAX], vet_odd[MAX], n, num, cont_even = 0, cont_odd = 0;

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &num);
        if(num % 2 == 0) {
            vet_even[cont_even] = num;
            cont_even++;
        } else {
            vet_odd[cont_odd] = num;
            cont_odd++;
        }
    }

    for(int i = 0; i < cont_even; i++) {
        printf("%d ", vet_even[i]);
    }

    printf("\n");

    for(int i = 0; i < cont_odd; i++) {
        printf("%d ", vet_odd[i]);
    }

    printf("\n");

    return 0;
}