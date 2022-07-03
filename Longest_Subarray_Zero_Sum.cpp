#include <bits/stdc++.h> 
int LongestSubsetWithZeroSum(vector < int > arr) {

  // Write your code here
    int maxx_sum=0;
    for(int i=0;i<arr.size();i++){
        int curr_sum=0;
        for(int j=i;j<arr.size();j++){
            curr_sum+=arr[j];
            
            if(curr_sum == 0)
                maxx_sum = max(maxx_sum,j-i+1);
        }    
    }
    return maxx_sum;
}
