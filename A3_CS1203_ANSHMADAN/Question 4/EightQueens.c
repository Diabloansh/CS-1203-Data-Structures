#include <stdio.h>
#include <stdbool.h>

#define N 8

// This method prints the chessboard with queens
void printBoard(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 1) {
                printf("Q ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

// Check if it is safe to place a queen at the given position
bool isSafe(int board[N][N], int row, int col) {
    int i, j;

    // Check the column on the left side
    for (i = 0; i < col; i++) {
        if (board[row][i]) {
            return false;
        }
    }

    // Check the upper diagonal on the left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    // Check the lower diagonal on the left side
    for (i = row, j = col; j >= 0 && i < N; i++, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    return true;
}

// Recursive utility function to solve the N Queens problem
bool solveNQueens(int board[N][N], int col) {
    if (col >= N) {
        return true; // All queens are placed
    }

    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1; // Place the queen

            if (solveNQueens(board, col + 1)) {
                return true;
            }

            board[i][col] = 0; // If placing queen doesn't lead to a solution, backtrack
        }
    }

    return false;
}

// Main function to solve and print the N Queens problem
void solveNQueensMain() {
    int board[N][N] = {0};

    if (solveNQueens(board, 0)) {
        printf("Solution exists:\n");
        printBoard(board);
    } else {
        printf("Solution does not exist\n");
    }
}

int main() {
    solveNQueensMain();
    return 0;
}
