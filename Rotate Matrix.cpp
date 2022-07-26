#include <bits/stdc++.h> 

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    if(m == 1) return; 
    for(int i = 0; i < min(n/2,m/2); i++)
    {
        int curr = mat[i][i];
        for(int j = i + 1; j < m - i; j++)
        {
            int t = mat[i][j];
            mat[i][j] = curr;
            curr = t;
        }
        for(int j = i + 1; j < n - i; j++)
        {
            int t = mat[j][m - i - 1];
            mat[j][m - i - 1] = curr;
            curr = t;
        }
        for(int j = m - i - 2; j >= i; j--)
        {
            int t = mat[n - i - 1][j];
            mat[n - i - 1][j] = curr;
            curr = t;
        }
        for(int j = n - i - 2; j > i; j--)
        {
            int t = mat[j][i];
            mat[j][i] = curr;
            curr = t;
        }
        mat[i][i] = curr;
    }
    
}
