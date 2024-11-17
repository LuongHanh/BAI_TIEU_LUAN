#include <iostream>
using namespace std;

#define N 8 // Kich thuoc ban co

// Kiem tra xem vi tri (row, col) co an toan khong
bool isSafe(int board[N][N], int row, int col) {
    // Kiem tra cot
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1)
            return false;
    }

    // Kiem tra duong cheo tren ben trai
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1)
            return false;
    }

    // Kiem tra duong cheo tren ben phai
    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

// Ham de quy giai bai toan xep 8 hau
bool solveNQueens(int board[N][N], int row) {
    if (row == N) { // Diem dung: Da xep du 8 quan hau
        return true;
    }

    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1; // Dat quan hau
            if (solveNQueens(board, row + 1)) // De quy
                return true;
            board[row][col] = 0; // Quay lui
        }
    }

    return false; // Khong tim duoc cach xep hop le
}

int main() {
    int board[N][N] = {0}; // Khoi tao ban co trong

    if (solveNQueens(board, 0)) {
        cout << "Ban co voi 8 quan hau xep hop le:" << endl;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == 1)
                    cout << "Q ";
                else
                    cout << ". ";
            }
            cout << endl;
        }
    } else {
        cout << "Khong tim duoc cach xep hop le." << endl;
    }

    return 0;
}

