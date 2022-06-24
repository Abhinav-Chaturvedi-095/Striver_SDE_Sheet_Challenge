#include <bits/stdc++.h>
bool compare(pair<int, int> p1, pair<int, int> p2)
{
    // if frequencies same then larger number first
    if (p1.second == p2.second)
        return p1.first > p2.first;
    // sort on the basis of decreasing order
    return p1.second > p2.second;
}
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    // Write your code here.
    unordered_map<int, int> u_map;
    for (int i = 0; i < n; i++)
        u_map[arr[i]]++;
    
    //map to vector for 
    vector<pair<int, int>> freq_arr(u_map.begin(), u_map.end());
    sort(freq_arr.begin(), freq_arr.end(), compare);
    vector<int> ans;
    for(int i=0;i<k;i++)
        ans.push_back(freq_arr[i].first);
    sort(ans.begin(),ans.end());
    return ans;
    
}
 
