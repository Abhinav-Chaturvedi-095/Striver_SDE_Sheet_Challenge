int calculateMinPatforms(int arr[], int dep[], int n) {
    // Write your code here.
    sort(arr, arr + n); 
        sort(dep, dep + n); 
    
        int plat_needed = 1, res = 1; 
        int i = 1, j = 0; 
     
        while (i < n && j < n) { 
            if (arr[i] <= dep[j]) { 
                plat_needed++; 
                i++; 
            }
            else if (arr[i] > dep[j]) { 
                plat_needed--; 
                j++; 
            } 
    
            if (plat_needed > res) 
                res = plat_needed; 
        } 
      
        return res; 
}
