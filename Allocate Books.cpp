#include <bits/stdc++.h>

bool isPossible(long long mid, vector<int> &time, int n, int m) {
    long long int ans = 1;
    long long int curr = 0;
    for(auto i : time) {
        curr += i;
        if(curr > mid) {
            ans++;
            curr = i;
        }
    }
    if(ans <= n) return true;
    return false;
}

long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{
    long long int low = 0, high = (long long int)1e14;
    for(auto i : time) low = max(low, (long long int)i);
    
    long long ans = 0;
    
    while(low <= high) {
        long long mid = low + (high - low)/2;
        
        if(isPossible(mid, time, n, m)) {
            ans = mid;
            high = mid - 1;
        } else low = mid + 1;
    }
    return ans;
}
