#include <bits/stdc++.h>

bool isPossible(int i, int j, int k, vector<vector<int>> &board) {
        
        for(int l = 0; l < 9; l++) {
            if(board[i][l] == k) return false;
            if(board[l][j] == k) return false;
        }
        
        int l = 3 * (i / 3);
        int m = 3 * (j / 3);
        
        for(int n = l; n < l + 3; n++) {
            for(int o = m; o < m + 3; o++) {
                if(board[n][o] == k) return false;
            }
        }
        
        return true;
    }
    
void sudokuSolver(int i, int j, vector<vector<int>> &board, vector<vector<int>> &ans, bool &flag) {
        if(i == board.size()) {
            ans = board;
            flag = false;
            return;
        }
        if(j == board.size()) 
        {
            sudokuSolver(i + 1, 0, board, ans, flag);
            return;
        }
        
        if(board[i][j] == 0) {
            for(int k = 1; k <= 9; k++) {
                if(isPossible(i, j, k, board)) {
                    board[i][j] = k ;
                    sudokuSolver(i, j + 1, board, ans, flag);
                    if(!flag) return;
                    board[i][j] = 0;
                }
            }
        } else {
            sudokuSolver(i, j + 1, board, ans, flag);
            if(!flag) return;
        }
        
        
    }

bool isItSudoku(int matrix[9][9]) {
        vector<vector<int>> board(9, vector<int> (9));
        vector<vector<int>> ans;
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            board[i][j] = matrix[i][j];
        }
    }
        bool flag = true;
        sudokuSolver(0, 0, board, ans, flag);
        return !flag;
}
