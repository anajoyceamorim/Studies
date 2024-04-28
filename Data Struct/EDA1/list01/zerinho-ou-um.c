#include <stdio.h>

int main() {
    int A, B, C;

    scanf("%d %d %d", &A, &B, &C);
    
    if (A == B && B == C) {
        printf("empate\n");
    } else if (A != B && A != C) {
        printf("A\n");
    } else if ( B != A && B != C) {
        printf("B\n");
    } else {
        printf("C\n");
    }
    
    return 0;
}