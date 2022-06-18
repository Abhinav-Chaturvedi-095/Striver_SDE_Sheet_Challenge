#include <bits/stdc++.h> 
int findMajorityElement(int arr[], int n) {
	// Write your code here.
//     int ans;
//     int n=arr.size();
    int threshold = floor(n/2);
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++)
        mp[arr[i]]++;
    for(auto x : mp)
        if(x.second>threshold)
            return x.first;
//             ans.push_back(x.first);
    return -1; 
}
