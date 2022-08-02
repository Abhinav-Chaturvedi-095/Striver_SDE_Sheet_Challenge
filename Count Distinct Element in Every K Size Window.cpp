#include<bits/stdc++.h>
vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    // Write your code here
	vector<int> ans;
    unordered_map<int,int> mp;
    int j=0,i=0;
    int n=arr.size();
    while(j<n){
        
        mp[arr[j]]++;
        if(j-i+1==k){
            ans.push_back(mp.size());
            mp[arr[i]]--;
            if(mp[arr[i]]==0)
            {
                mp.erase(arr[i]);
            }
            i++;
        }
        j++;
    }
    return ans;
}
