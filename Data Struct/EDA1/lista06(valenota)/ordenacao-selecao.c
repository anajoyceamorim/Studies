#include <stdio.h>
#define MAX 1123

void swap (int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        int* el = &arr[i];
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < *el) el = &arr[j];
        }
        swap(el, &arr[i]);
    }
}

int main() {

    int array[MAX];

    int i = 0;
    while (scanf("%d ", &array[i++]) != EOF);
        selection_sort(array, --i);
    
    for (int j = 0; j < i; j++)
        printf("%d ", array[j]);
    
    printf("\n");

    return 0;
}