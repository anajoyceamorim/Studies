#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int col;
    int value;
    struct Node* next;
} Node;

void insert(Node** head, int col, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->col = col;
    newNode->value = value;
    newNode->next = *head;
    *head = newNode;
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    Node** matrix = (Node**)malloc(m * sizeof(Node*));
    for (int i = 0; i < m; i++) {
        matrix[i] = NULL;
    }

    int row, col, value;
    while (scanf("%d %d %d", &row, &col, &value) && (row != -1 || col != -1 || value != -1)) {
        insert(&matrix[row], col, value);
    }

    int* vector = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &vector[i]);
    }

    int* result = (int*)calloc(m, sizeof(int));

    for (int i = 0; i < m; i++) {
        Node* current = matrix[i];
        while (current != NULL) {
            result[i] += current->value * vector[current->col];
            current = current->next;
        }
    }

    for (int i = 0; i < m; i++) {
        printf("%d\n", result[i]);
    }

    for (int i = 0; i < m; i++) {
        Node* current = matrix[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(matrix);
    free(vector);
    free(result);

    return 0;
}
