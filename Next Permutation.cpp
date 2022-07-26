#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &p, int n)
{
    int i = n - 2, j =  n- 1;
    while(i >= 0 && p[i] >= p[i + 1]) i--;
    
    if(i < 0) {
        reverse(p.begin(),p.end());
    } else {
        while(p[j] <= p[i]) j--;
        swap(p[i],p[j]);
        reverse(p.begin() + i + 1,p.end());
    }
    return p;
}
