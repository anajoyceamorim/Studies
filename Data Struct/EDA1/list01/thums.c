#include <stdio.h>

void thums (int num) {
    for (int i = 0; i < num; i++) {
        if ( i % 2 == 0 ) {
            printf("THUMS THUMS THUMS\n");
        } else {
            printf("THUMS THUMS THUMS THUMS THUMS THUMS\n");
        }
    }
}

int main () {

    int num;
    scanf("%d", &num);

    thums(num);

    return 0;
}