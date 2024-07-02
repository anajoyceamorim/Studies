#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_SIZE 100

typedef struct {
    char **data;
    int top;
    int capacity;
} Stack;

void initStack(Stack *stack, int initialCapacity) {
    stack->data = (char **)malloc(initialCapacity * sizeof(char *));
    stack->top = -1;
    stack->capacity = initialCapacity;
}

void freeStack(Stack *stack) {
    for (int i = 0; i <= stack->top; i++) {
        free(stack->data[i]);
    }
    free(stack->data);
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

void resizeStack(Stack *stack, int newCapacity) {
    stack->data = (char **)realloc(stack->data, newCapacity * sizeof(char *));
    stack->capacity = newCapacity;
}

void push(Stack *stack, const char *str) {
    if (stack->top == stack->capacity - 1) {
        resizeStack(stack, stack->capacity * 2);
    }
    stack->data[++stack->top] = strdup(str);
}

char *pop(Stack *stack) {
    if (isEmpty(stack)) {
        return "NULL";
    }
    return stack->data[stack->top--];
}

int main() {
    Stack stack;
    initStack(&stack, 10); 

    char input[MAX_STR_SIZE + 8]; 

    while (fgets(input, sizeof(input), stdin) != NULL) {
        input[strcspn(input, "\n")] = '\0';

        if (strncmp(input, "inserir ", 8) == 0) {
            push(&stack, input + 8);
        } else if (strcmp(input, "desfazer") == 0) {
            char *result = pop(&stack);
            printf("%s\n", result);
            if (strcmp(result, "NULL") != 0) {
                free(result);
            }
        }
    }

    freeStack(&stack);
    return 0;
}
