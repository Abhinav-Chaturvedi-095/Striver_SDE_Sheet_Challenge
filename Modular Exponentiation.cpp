#include <bits/stdc++.h> 
long long int power(int x,int n,int m){
    if(x==0)
    {
        return 0;
    }
    if(n==0)
    {
        return 1;
    }
    long long int ans;
    if(n%2==0)//even
    {
        long long int small_ans=power(x, n/2, m);
        ans=(small_ans*small_ans)%m;
    }
    else//odd
    {
        long long int small_ans=power(x, n-1, m);
        ans=((x%m)*small_ans)%m;
    }
    return (ans+m)%m;
}


int modularExponentiation(int x, int n, int m) {
    // Write your code here.
   return power (x,n,m);
}
