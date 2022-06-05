#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   //   Write your code here
    int count_0=0,count_2=0;
    
    for(int i=0;i<n;i++){
        if(arr[i]==0) count_0++;
        else if(arr[i]==2) count_2++;
//         else count_2++;
    }
    for(int i=0;i<count_0;i++){
        arr[i]=0;
    }
    for(int i=count_0;i<(n-count_2);i++){
        arr[i]=1;
    }
    for(int i=(n-count_2);i<n;i++){
        arr[i]=2;
    }
}
