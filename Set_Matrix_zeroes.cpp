#include <bits/stdc++.h> 
void setZeros(vector<vector<int>> &matrix)
{
	// Write your code here.
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> row(m,-1);
    vector<int> column(n,-1);
    
    //identifying zeroes place
    for(int i=0;i<m;i++) { 
        for(int j=0;j<n;j++) {
            if(matrix[i][j]==0) {
                row[i]=0;
                column[j]=0;
            }
        }
    }
    
    //setting zeroes
    for(int i=0;i<m;i++){
        if(row[i]==0){
            for(int j=0;j<n;j++){
                matrix[i][j]=0;
            }
        }
        else 
            continue;
    }
    for(int i=0;i<n;i++){
        if(column[i]==0){
            for(int j=0;j<m;j++){
                matrix[j][i]=0;
            }
        }
        else 
            continue;
    }
    
    
        //T.C. = O(m*n)+O(m*n)+O(n*m) = O(m*n)
}
