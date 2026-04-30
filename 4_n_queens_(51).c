#include <stdio.h>

#define N 4

int board[N][N];

int isSafe(int row, int col) {
    for(int i = 0; i < col; i++)
        if(board[row][i]) return 0;

    for(int i=row, j=col; i>=0 && j>=0; i--, j--)
        if(board[i][j]) return 0;

    for(int i=row, j=col; j>=0 && i<N; i++, j--)
        if(board[i][j]) return 0;

    return 1;
}

void solve(int col) {
    if(col == N) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++)
                printf("%d ", board[i][j]);
            printf("\n");
        }
        printf("\n");
        return;
    }

    for(int i = 0; i < N; i++) {
        if(isSafe(i, col)) {
            board[i][col] = 1;
            solve(col + 1);
            board[i][col] = 0;
        }
    }
}

int main() {
    solve(0);
    return 0;
}
