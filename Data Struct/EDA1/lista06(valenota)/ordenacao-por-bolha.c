#include <stdio.h>

#define MAX 1123

void swap(int* a, int* b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

void bubble_sort(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n - i; j++) {
            if (arr[j - 1] > arr[j]) swap(&arr[j - 1], &arr[j]);
        }
    }
}

int main() {
    int arr[MAX];

    int i = 0;
    while (scanf("%d ", &arr[i++]) != EOF);

    bubble_sort(arr, --i);

    for (int j = 0; j < i; j++) printf("%d ", arr[j]);
    printf("\n");

    return 0;
}