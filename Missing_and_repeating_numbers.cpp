#include <bits/stdc++.h> 

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
    pair<int,int> ans;
    int arr_sum=0;
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
        arr_sum+=arr[i];
    }
    for(auto x: mp)
        if(x.second==2)
            ans.second=x.first;
    
    int sum=n*(n+1)/2;
    ans.first=sum-(arr_sum-ans.second);
    return ans;
}
