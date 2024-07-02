//Questão com problema
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 102

typedef struct {
    int x, y;
    int dist;
} Ponto;

typedef struct {
    int x, y;
} Torre;

char terreno[MAX][MAX];
int visiveis[MAX][MAX];
int N, M;

void bfs(int x, int y, int altura) {
    Ponto fila[MAX * MAX];
    int frente = 0, tras = 0;
    
    fila[tras++] = (Ponto){x, y, 0};
    visiveis[x][y] = 1;

    int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
    int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};

    while (frente < tras) {
        Ponto p = fila[frente++];
        for (int j = 0; j < 8; j++) {
            int nx = p.x + dx[j];
            int ny = p.y + dy[j];
            if (nx >= 0 && nx < N && ny >= 0 && ny < M && p.dist < altura) {
                if (visiveis[nx][ny] == 0 && terreno[nx][ny] == '#') {
                    fila[tras++] = (Ponto){nx, ny, p.dist + 1};
                    visiveis[nx][ny] = 1;
                }
            }
        }
    }
}

int main() {
    if (scanf("%d %d", &N, &M) != 2) {
        fprintf(stderr, "Erro ao ler N e M\n");
        return 1;
    }

    for (int i = 0; i < N; i++) {
        if (scanf("%s", terreno[i]) != 1) {
            fprintf(stderr, "Erro ao ler a linha %d do terreno\n", i);
            return 1;
        }
    }

    int T;
    if (scanf("%d", &T) != 1) {
        fprintf(stderr, "Erro ao ler T\n");
        return 1;
    }

    int alturas[T];
    Torre torres[T];
    int indiceTorre = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (terreno[i][j] == 't') {
                torres[indiceTorre++] = (Torre){i, j};
            }
        }
    }

    for (int i = 0; i < T; i++) {
        if (scanf("%d", &alturas[i]) != 1) {
            fprintf(stderr, "Erro ao ler altura da torre %d\n", i);
            return 1;
        }
    }

    memset(visiveis, 0, sizeof(visiveis));

    for (int i = 0; i < T; i++) {
        bfs(torres[i].x, torres[i].y, alturas[i]);
    }

    int areasVisiveis = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (terreno[i][j] == '#' && visiveis[i][j] == 1) {
                terreno[i][j] = '.';
                areasVisiveis++;
            }
        }
    }

    printf("%d\n", areasVisiveis);
    for (int i = 0; i < N; i++) {
        printf("%s\n", terreno[i]);
    }

    return 0;
}
