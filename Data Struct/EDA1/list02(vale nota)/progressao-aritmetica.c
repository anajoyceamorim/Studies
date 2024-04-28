#include <stdio.h>

int pa_recursiva (int *v, int primeiro, int ultimo) {
    if (ultimo - primeiro == 1) return 1;
    if (v[primeiro] + v[ultimo] != v[primeiro + 1] + v[ultimo - 1]) return 0;
    pa_recursiva(v, primeiro + 1, ultimo - 1);

}

/*
int main() {

    int v[6] = {1, 3, 5, 7, 9, 11};
    
    int asw = pa_recursiva(v, 0, 6-1);

    printf("%d\n", asw);

    return 0;
}
*/