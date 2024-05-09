#include<stdio.h>

int binary_search(int* arr, int n, int v) {
    int l = 0, r = n;

    while( l <= r ){
        int m = (l + r) / 2;

        if (arr[m] == v) return 1;
        else if (arr[m] < v) l = m + 1;
        else r = m - 1;
    }
    return 0;
}

int main() {

    int arr[] = {1, 2, 3, 4, 6, 7, 8, 9};

    printf("tem? %d\n", binary_search(arr, sizeof(arr) / sizeof(int), 2));
    printf("tem? %d\n", binary_search(arr, sizeof(arr) / sizeof(int), 5));

    return 0;
}
