#include<bits/stdc++.h>
double median(vector<int> a, vector<int> b)
{
    // Write your code here.
    vector<int> arr;
    int i=0,j=0;
    while(i!=a.size()&&j!=b.size()){
        if(a[i]>b[j]){
            arr.push_back(b[j]);
            j++;
        }
        else if(a[i]<=b[j]){
            arr.push_back(a[i]);
            i++;
        }
    }
    if(i==a.size())
        for(int k=j;k<b.size();k++)
            arr.push_back(b[k]);
    else if(j==b.size())
        for(int k=i;k<a.size();k++)
            arr.push_back(a[k]);
    
    int n=arr.size();
//     for(int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
    
    if(n%2==0){
        double x=(arr[n/2-1]+arr[n/2]);
//         cout<<endl<<arr[n/2-1]<<" " <<arr[n/2];
//         cout<<endl<<x<<endl;
        return x/2;
    }
        
    else{
        int x = arr[floor(n/2)];    
//         cout<<endl<<arr[floor(n/2)];
//         cout<<endl<<x<<endl;
        return x;
    }
}
