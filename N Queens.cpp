#include <bits/stdc++.h>
bool isPossible(int i, int j, vector<vector<int>> &board) {
        
        for(int k = 0; k < board.size(); k++) {
            if(board[i][k] == 1) return false;
            if(board[k][j] == 1) return false;
        }
        
        int l = i, h = j;
        while(l < board.size() && h < board.size()) {
            if(board[l][h] == 1) return false;
            l++;
            h++;
        }
        
        l = i, h = j;
        while(l < board.size() && h >= 0) {
            if(board[l][h] == 1) return false;
            l++;
            h--;
        }
        
        l = i, h = j;
        while(l >= 0 && h < board.size()) {
            if(board[l][h] == 1) return false;
            l--;
            h++;
        }
        
        l = i, h = j;
        while(l >= 0 && h >= 0) {
            if(board[l][h] == 1) return false;
            l--;
            h--;
        }
        
        return true;
        
    }
    
    void nQueen(int i, vector<vector<int>> &board, vector<vector<int>> &ans) {
        if(i == board.size()) {
            vector<int> temp;
            for(int i = 0; i < board.size(); i++) {
                for(int j = 0; j < board.size(); j++) {
                    temp.push_back(board[i][j]);
                }
            }
            ans.push_back(temp);
            return;
        }
        
        for(int j = 0; j < board.size(); j++) {
            if(isPossible(i, j, board)) {
                board[i][j] = 1;
                nQueen(i + 1, board, ans);
                board[i][j] = 0;
            }
        }
    }

    vector<vector<int>> solveNQueens(int n) {
        vector<vector<int>> ans;
        vector<vector<int>> board(n, vector<int> (n));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                board[i][j] = 0;
            }
        }
        
        nQueen(0, board, ans);
        
        return ans;
}
