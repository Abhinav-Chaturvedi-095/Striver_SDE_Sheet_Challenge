#include<bits/stdc++.h>
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	// Write your code here.
    priority_queue<int> pq;
    vector<int> ans;
 
    // insert all the possible combinations in max heap.
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            pq.push(a[i] + b[j]);
 
    // pop first N elements from max heap
    int count = 0;
    while (count < k) {
        ans.push_back(pq.top());
        pq.pop();
        count++;
    }
    return ans;
}
