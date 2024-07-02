#include <swap.h>

void selection_sort (int v[], int l, int r)
{
    int menor;

    for(int i = l; i<r; i++) {
        menor = i;
        for(int j=i+1; j<=r; j++){
            if(v[j] < v[menor])
                menor = j;
        }
        if(i != menor)
            swap (v[i], v[menor]);
    }
}