#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int *data;    
    int capacity; 
    int size;    
} PriorityQueue;

void swap(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

void fixUp(PriorityQueue *pq, int k)
{
    while (k > 1 && pq->data[k] < pq->data[k / 2])
    {
        swap(&pq->data[k], &pq->data[k / 2]);
        k = k / 2;
    }
}

void fixDown(PriorityQueue *pq, int k, int N)
{
    while (2 * k <= N)
    {
        int j = 2 * k;

        if (j < N && pq->data[j] > pq->data[j + 1])
            j++;

        if (pq->data[k] <= pq->data[j])
            break;

        swap(&pq->data[k], &pq->data[j]);
        k = j;
    }
}

void PQInit(PriorityQueue *pq, int capacity)
{
    pq->data = (int *)malloc(capacity * sizeof(int));
    pq->capacity = capacity;
    pq->size = 0;
}

void PQInsert(PriorityQueue *pq, int item)
{
    pq->data[++pq->size] = item;

    fixUp(pq, pq->size);
}

int PQdelmin(PriorityQueue *pq)
{
    swap(&pq->data[1], &pq->data[pq->size]);

    fixDown(pq, 1, pq->size - 1);

    return pq->data[pq->size--];
}

void PQchange(PriorityQueue *pq, int k, int valor)
{
    if (pq->data[k] < valor)
    {
        pq->data[k] = valor;
        fixDown(pq, k, pq->size);
    }
    else
    {
        pq->data[k] = valor;
        fixUp(pq, k);
    }
}

int main()
{
    int O, P;
    PriorityQueue pq;
    PQInit(&pq, 100);

    while (scanf("%d %d", &O, &P) == 2)
    {

        if (O == 1)
        {
            if (pq.size == 100)
            {
                int maior = pq.size;
                for (int i = pq.size / 2; i < pq.size; i++)
                {
                    if (pq.data[i] > pq.data[maior])
                    {
                        maior = i;
                    }
                }
                if (pq.data[maior] > P)
                    PQchange(&pq, maior, P);
                
            }
            else
                PQInsert(&pq, P);
            
        }
        else
        {
            int aux[100];
            for (int i = 0; i < P; i++)
            {
                aux[i] = PQdelmin(&pq);
                printf("%d ", aux[i]);
            }
            for (int i = 0; i < P; i++)
            {
                PQInsert(&pq, aux[i]);
            }
            printf("\n");
        }
    }

    return 0;
}