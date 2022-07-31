#include <bits/stdc++.h> 
int merge(int low,int mid,int high,vector<int> &arr,vector<int> &sorted)
{
    
    int i = low,j = mid + 1,k = low;
    int ans = 0;
    for(int i = low; i <= mid; i++)
    {
        while(j <= high && arr[i] > 2ll*arr[j]) j++;
        ans += (j - mid - 1);
    }
    i = low,j = mid + 1;
    while(i <= mid && j <= high)
    {
        if(arr[i] <= arr[j]) {
            sorted[k] = arr[i];
            i++;
            k++;
        } else {
            sorted[k] = arr[j];
            j++;
            k++;
        }
    }
    while(i <= mid)
    {
        sorted[k] = arr[i];
        i++;
        k++;
    }
    while(j <= high)
    {
        sorted[k] = arr[j];
        j++;
        k++;
    }
    for(int i = low; i <= high; i++) arr[i] = sorted[i];
    return ans;
}


int countInversions(int low, int high, vector<int> &arr,vector<int> &sorted)
{
    int mid = (low + high)/2;
    int ans = 0;
    if(low < high)
    {
        ans += countInversions(low,mid,arr,sorted);
        ans += countInversions(mid + 1,high,arr,sorted);
        
        ans += merge(low,mid,high,arr,sorted);
    }
    return ans;
}


int reversePairs(vector<int> &arr, int n){
	// Write your code here.	
     vector<int> sorted(n);
     return countInversions(0,n - 1,arr,sorted);
}
