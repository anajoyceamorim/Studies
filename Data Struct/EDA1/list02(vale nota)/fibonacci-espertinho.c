#include <stdio.h>

long int memo[81] = { 0 };

long int fibonacci (int n) {
    if(n <= 2) return 1;
    if(!memo[n]) memo[n] = fibonacci(n - 1) + fibonacci( n - 2);
    return memo[n];
}

/*
int main() {

    int n, asw;

    scanf("%d", &n);

    asw = fibonacci(n);
    printf("%d\n", asw);

    return 0;
}
*/