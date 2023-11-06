#include <iostream>
using namespace std;

const int N = 9;

void printBoard(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool isValid(int board[N][N], int row, int col, int num) {
    for (int x = 0; x < N; x++) {
        if (board[row][x] == num || board[x][col] == num) {
            return false;
        }
    }

    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }

    return true;
}

bool solveSudoku(int board[N][N]) {
    int row, col;

    bool isEmpty = true;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 0) {
                row = i;
                col = j;
                isEmpty = false;
                break;
            }
        }
        if (!isEmpty) {
            break;
        }
    }

    if (isEmpty) {
        return true; // Board is solved
    }

    for (int num = 1; num <= 9; num++) {
        if (isValid(board, row, col, num)) {
            board[row][col] = num;

            if (solveSudoku(board)) {
                return true;
            }

            board[row][col] = 0; //Backtrack
        }
    }

    return false;
}

int main() {
    int board[N][N] = {{6,5,0,8,7,3,0,9,0},
                       {0,0,3,2,5,0,0,0,8},
                       {9,8,0,1,0,4,3,5,7},
                       {1,0,5,0,0,0,0,0,0},
                       {4,0,0,0,0,0,0,0,2},
                       {0,0,0,0,0,0,5,0,3},
                       {5,7,8,3,0,1,0,2,6},
                       {2,0,0,0,4,8,9,0,0},
                       {0,9,0,6,2,5,0,8,1}};

    if (solveSudoku(board)) {
        cout << "Solved Sudoku:" << endl;
        printBoard(board);
    } else {
        cout << "No solution exists" << endl;
    }

    return 0;
}
