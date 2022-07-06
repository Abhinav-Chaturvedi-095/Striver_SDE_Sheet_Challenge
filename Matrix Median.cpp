#include<bits/stdc++.h>
int getMedian(vector<vector<int>> &matrix)
{
    // Write your code here.
    int m=matrix.size();
    int n=matrix[0].size();
    
    vector<int> list;
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            list.push_back(matrix[i][j]);
        }
    }
    
    sort(list.begin(),list.end());
    int x=list.size();
    if(x%2==0) x=x/2+1;
    else x=x/2;
    int median = list[x];
    return median;
}

//use binary search for optimal solution
