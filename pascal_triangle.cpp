#include <bits/stdc++.h> 
vector<vector<long long int>> printPascal(int n) 
{
  // Write your code here.
    vector<vector<long long int>> ans;
        if(n==0) return ans;
        
    //for first row
        vector<long long int> x;
        x.push_back(1);
        ans.push_back(x);
        
        if(n==1) return ans;
        
    //for second row
        vector<long long int> y;
        y.push_back(1);
        y.push_back(1);
        ans.push_back(y);
    
    //for n rows 
    for(long long int i=2;i<n;i++){
            vector<long long int> temp;
            temp.push_back(1);//zeroth index of ith row
            for(long long int j=1;j<i;j++){
                long long int k=ans[i-1][j-1]+ans[i-1][j];
                temp.push_back(k);
            }
            temp.push_back(1);//(i-1)th index of ith row
            ans.push_back(temp);//pushing ith row in ans vector
        }
    return ans;
}
