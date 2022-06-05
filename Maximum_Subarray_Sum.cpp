#include <bits/stdc++.h> 
#define ll long long
long long maxSubarraySum(int arr[], int n)
{
    /*
        Don't write main().
        Don't read input, it is passed as function argument.    
        No need to print anything.
        Taking input and printing output is handled automatically.
    */
    //kadane algo
    ll max_neg=arr[0];
    ll max=0,cur=0;
    for(ll i=0;i<n;i++){
        cur+=arr[i];
        if(arr[i]>max_neg) max_neg=arr[i];
        if(cur>max) max=cur;
        if(cur<0) cur=0;
    }
    if(max_neg<0) return 0;
    return max;
}
