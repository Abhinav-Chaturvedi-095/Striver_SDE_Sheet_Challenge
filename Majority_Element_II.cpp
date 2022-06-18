#include <bits/stdc++.h> 
vector<int> majorityElementII(vector<int> &arr)
{
    // Write your code here.
    vector<int> ans;
    int n=arr.size();
    int threshold = floor(n/3);
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++)
        mp[arr[i]]++;
    for(auto x : mp)
        if(x.second>threshold) 
            ans.push_back(x.first);
    return ans; 
}
