#include <bits/stdc++.h>

bool isPossible(vector<int> &positions, int n, int c, int mid) {
    int count = 1;
    int prev = positions[0];
    for(int i = 1; i < n; i++) {
        if(positions[i] - prev >= mid) 
        {
            prev = positions[i];
            count++;
        }
    }
    if(count >= c) return true;
    return false;
}

int chessTournament(vector<int> positions , int n ,  int c){
    sort(positions.begin(), positions.end());
    int low = 1, high = positions[n - 1] - positions[0];
    int ans;
    while(low <= high) {
        int mid = low + (high - low)/2;
        
        if(isPossible(positions, n, c, mid)) {
            ans = mid;
            low = mid + 1;
        } else high = mid - 1;
    }
    return ans;
}
