#include <bits/stdc++.h> 
int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.
    int n=arr.size();
    int ans=0;
    int prefixXor = 0;
    unordered_map<int, int> countOfPrefixXor;
    for(int i=0;i<n;i++){
        prefixXor ^= arr[i];
            if(prefixXor==x)
                ans++;
        if (countOfPrefixXor[prefixXor ^ x] != 0) 
            ans += countOfPrefixXor[prefixXor ^ x];
        
        countOfPrefixXor[prefixXor]++;

        
    }
    return ans;
}

//tc: O(n)
