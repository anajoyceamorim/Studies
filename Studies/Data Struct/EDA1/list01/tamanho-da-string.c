#include <stdio.h>
#include <string.h>

#define MAX 1012

int main () {

    char string[MAX];

    fgets(string, sizeof(string), stdin);

    for (int i = 0; i < MAX; i++) {
        if (string[i] == '\0') {
            printf("%d\n", i-1);
            break;
        }
    }
    
    return 0;
}