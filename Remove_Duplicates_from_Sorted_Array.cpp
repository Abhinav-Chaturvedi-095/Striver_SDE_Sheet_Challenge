int removeDuplicates(vector<int> &arr, int n) {
	// Write your code here.
    
    if (n==0 || n==1)
        return n;
    int j=0;
    for(int i=0;i<n-1;i++)
        if(arr[i]!=arr[i+1]){
            arr[j]=arr[i];
            j++;
        }
    arr[j] = arr[n-1];
    j++;
    return j;
    
//     for(int i=1;i<n;i++){
//         if(arr[i-1]==arr[i]){
//             n=n-1;
//             for (int j=i; j<n; j++)
//                 arr[j] = arr[j+1];
//             i--;            
//         }
//     }
//     return n;
}
