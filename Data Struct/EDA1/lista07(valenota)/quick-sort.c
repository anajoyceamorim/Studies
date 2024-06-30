#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef SWAP_LIB
#define SWAP_LIB
#endif
#ifndef QUICK_SORT_LIB
#define QUICK_SORT_LIB
#endif

void swap(int* a, int* b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

int partition(int* arr, int l, int r) {
    int pivot = arr[r], j = l;

    for (int i = l; i < r; i++) {
        if (arr[i] < pivot) swap(&arr[i], &arr[j++]);
    }
    swap(&arr[j], &arr[r]);

    return j;
}

void quick_sort(int* arr, int l, int r) {
    if (l > r) return;

    int p = partition(arr, l, r);
    quick_sort(arr, l, p - 1);
    quick_sort(arr, p + 1, r);
}

void quick_sort_median(int* arr, int l, int r) {
    if (l > r) return;

    int m = l + (r - l) / 2;
    if (arr[m] < arr[l]) swap(&arr[m], &arr[l]);
    if (arr[r] < arr[l]) swap(&arr[l], &arr[r]);
    if (arr[m] < arr[r]) swap(&arr[r], &arr[m]);

    int p = partition(arr, l, r);
    quick_sort_median(arr, l, p - 1);
    quick_sort_median(arr, p + 1, r);
}

int main() {
    int n;
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    quick_sort_median(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        if (i > 0) printf(" ");
        printf("%d", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}
