#include <stdio.h>

int binary_search (int* array, int size, int key) {
    int l = 0, r = size - 1;

    while (l <=r)
    {
        int middle = l + (r - l) / 2;

        if (array[middle] >= key) r = middle - 1;
        else l = middle + 1;
    }
    
    return l;
}

int main(){

    int n, m, key;
    scanf ("%d %d", &n, &m);
    int array[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    while (m--) {
        scanf("%d", &key);

        int asw = binary_search(array, n, key);
        printf("%d\n", asw);
    }

    return 0;
}
