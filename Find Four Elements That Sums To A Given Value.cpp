#include <bits/stdc++.h> 
string fourSum(vector<int> arr, int X, int n) {
    // Write your code here.
    unordered_map<int, pair<int, int> > mp;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            mp[arr[i] + arr[j]] = { i, j };
 
    // Traverse through all pairs and search for X - (current pair sum).
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum = arr[i] + arr[j];
 
            // If X - sum is present in hash table,
            if (mp.find(X - sum) != mp.end()) {
 
                // Making sure that all elements are distinct array elements.
                pair<int, int> p = mp[X - sum];
                if (p.first != i && p.first != j && p.second != i && p.second != j) {
                    
                    return "Yes";
                }
            }
        }
    }
    return "No";
}
