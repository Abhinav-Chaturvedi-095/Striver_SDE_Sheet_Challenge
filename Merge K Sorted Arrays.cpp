#include <bits/stdc++.h>
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<int> pq;
    for(auto i : kArrays) {
        for(auto j : i) pq.push(j);
    }
    vector<int> ans;
    while(pq.size()) {
        ans.push_back(pq.top());
        pq.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
