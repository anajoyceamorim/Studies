#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 8

typedef struct {
    int row;
    int col;
} Position;

int knightMoves[8][2] = {
    {-2, -1}, {-1, -2}, {1, -2}, {2, -1},
    {2, 1}, {1, 2}, {-1, 2}, {-2, 1}
};

int isValid(int row, int col) {
    return (row >= 0 && row < MAX_N && col >= 0 && col < MAX_N);
}

int bfs(Position start, Position end) {
    int visited[MAX_N][MAX_N];
    memset(visited, 0, sizeof(visited));
    
    visited[start.row][start.col] = 1;
    
    int queue[MAX_N * MAX_N][3];
    int front = 0, rear = 0;
    queue[rear][0] = start.row;
    queue[rear][1] = start.col;
    queue[rear][2] = 0;
    rear++;
    
    while (front < rear) {
        int currentRow = queue[front][0];
        int currentCol = queue[front][1];
        int currentDist = queue[front][2];
        front++;
        
        if (currentRow == end.row && currentCol == end.col) {
            return currentDist;
        }
        
        for (int i = 0; i < 8; i++) {
            int nextRow = currentRow + knightMoves[i][0];
            int nextCol = currentCol + knightMoves[i][1];
            
            if (isValid(nextRow, nextCol) && !visited[nextRow][nextCol]) {
                visited[nextRow][nextCol] = 1;
                queue[rear][0] = nextRow;
                queue[rear][1] = nextCol;
                queue[rear][2] = currentDist + 1;
                rear++;
            }
        }
    }
    
    return -1;
}

Position parsePosition(char* posStr) {
    Position pos;
    pos.col = posStr[0] - 'a';
    pos.row = posStr[1] - '1';
    return pos;
}

int main() {
    char pos1[3], pos2[3];
    
    while (scanf("%s %s", pos1, pos2) != EOF) {
        Position start = parsePosition(pos1);
        Position end = parsePosition(pos2);
        
        int moves = bfs(start, end);
        
        printf("To get from %s to %s takes %d knight moves.\n", pos1, pos2, moves);
    }
    
    return 0;
}
