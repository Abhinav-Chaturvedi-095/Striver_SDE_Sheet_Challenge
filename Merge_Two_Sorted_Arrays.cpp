#include <bits/stdc++.h> 
vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	// Write your code here.
     int i=0,j=0;
        int M=m;
        if(m==0) arr1=arr2;
        else if(n==0);
        else{
            while(j<n ){
                if(i==m) break;
               else if(arr1[i]>=arr2[j]){
                  arr1.pop_back();
                arr1.insert(arr1.begin()+i, arr2[j]);
                j++;
                i++;
                m++;
            }
            else {
                i++;
               
            }                    
        }
        
        if(j<n){
            while(i<M+n){
                arr1.pop_back();
                arr1.insert(arr1.begin()+i, arr2[j]);
                j++;
               i++;
            }
         }  
        }
    return arr1;
}
