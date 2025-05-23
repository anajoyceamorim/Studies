#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void merge(int* arr, int p, int q, int r) {
    int* z = (int*)malloc((r - p) * sizeof(int));

    int i = p, j = q, k = 0;
    while (i < q && j < r) z[k++] = arr[i] <= arr[j] ? arr[i++] : arr[j++];

    while (i < q) z[k++] = arr[i++];
    while (j < r) z[k++] = arr[j++];

    for (i = p; i < r; i++)  arr[i] = z[i - p];
    free(z);
}

void merge_sort(int* arr, int p, int r) {
    if (p >= r - 1) return;

    int q = p + (r - p) / 2;
    merge_sort(arr, p, q);
    merge_sort(arr, q, r);
    merge(arr, p, q, r);
}

int main() {
    int n;
    scanf(" %d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) scanf(" %d", &arr[i]);

    merge_sort(arr, 0, n);

    for (int j = 0; j < n; j++) {
        printf("%d", arr[j]);
        if (j != n - 1) printf(" ");
    }
    printf("\n");

    return 0;
}
