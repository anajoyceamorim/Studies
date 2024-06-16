#include <stdio.h>

typedef int Item;
#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B)  \
    {               \
        Item t = A; \
        A = B;      \
        B = t;      \
    }
#define compexch(A, B) \
    if (less(B, A))    \
    exch(A, B)

void insertion_sort(int v[], int l, int r)
{
    int i, j, elem;

    for (i = r; i > l; i--)
        compexch(v[l], v[i]);

    for (i = l + 2; i <= r; i++)
    {
        elem = v[i];
        for (j = i; elem < v[j - 1]; j--)
            v[j] = v[j - 1];
        v[j] = elem;
    }
}

int main()
{
    int v[50000];
    int n = 0;

    while (scanf("%d", &v[n]) != EOF)
    {
        n++;
    }

    insertion_sort(v, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}