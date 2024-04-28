#include <stdio.h>

int main() {

    int num, n, index = -1, min = __INT_MAX__;

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &num);
        if(num < min ) {
            min = num;
            index = i;
        }
    }

    printf("%d\n", index);

    return 0;
}