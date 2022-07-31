int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) {
    // Write your code here.
     int low = 0, high = 1e5;
    while(low <= high) {
        int mid = low + (high-low)/2;
        
        int count = (upper_bound(row1.begin(), row1.end(), mid) - row1.begin()) + (upper_bound(row2.begin(), row2.end(), mid) - row2.begin());
        
        if(count < k) low = mid + 1;
        else high = mid - 1;
    }
    
    return low;
}
/*
int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) {
    // Write your code here.
    int target=0,i=0,j=0;
    
    while(i<m && j<n){
        if(row1[i]<=row2[j]) 
        {
            target++;
            if(target==k) return row1[i];
            i++;
        }
        else
        {
            target++;
            if(target==k) return row2[j];
            j++;
        }
    }
    
    while(j<n){
        target++;
        if(target==k) return row2[j];
        j++;    
    }
    
    while(i<m){
        target++;
        if(target==k) return row1[i];
        i++;    
    }
}
*/
// int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) {
//     // Write your code here.
//     int i=0,j=0,temp=0;
//     for(int i=0,j=0;i<m||j<n;){
//         if(row1[i]<=row2[j] && i<m){
//             if(i+j==k-1) return row1[i];
//             i++;
//         }
//         else{
//             if(i+j==k-1 && j<n) return row2[j];
//             j++;
//         }
//     }
// }
/*
int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) {
    // Write your code here.
    int target=0,i=0,j=0;
    
    while(i<m && j<n){
        if(row1[i]<=row2[j]) 
        {
            if(target==k-1) return row1[i];
            target++,i++;
        }
        else if(row1[i]>row2[j])
        {
            if(target==k-1) return row2[j];
            j++,target++;
        }
    }
    if(i==m)
    {
        while(j!=n){
            if(target==k-1) return row2[j];
            j++,target++;    
        }
    }
    if(j==n)
    {
        while(i!=m){
            if(target==k-1) return row1[i];
            i++,target++;    
        }
    }
//     return row2[target];
}
*/
