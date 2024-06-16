#ifndef SWAP_LIB
#define SWAP_LIB
#endif
#ifndef MIN_INDEX_LIB
#define MIN_INDEX_LIB
#endif

void swap(int* a, int* b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

int min_index(int* arr, int i, int j) {
    if (i == j) return i;

    int k = min_index(arr, i + 1, j);
    return (arr[i] < arr[k]) ? i : k;
}

void selection_sort_rec(int* arr, int n, int i) {
    if (i == n) return;

    int k = min_index(arr, i, n - 1);
    swap(&arr[i], &arr[k]);
    selection_sort_rec(arr, n, i + 1);
}

void ordena(int* v, int n) {
    selection_sort_rec(v, n, 0);
}