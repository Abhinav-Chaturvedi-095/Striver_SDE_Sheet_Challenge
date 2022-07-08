int subsetsum(int n,int k ,vector<int>&arr,vector<vector<int>>&dp){
    // base case
    if (k== 0 )
        return 1;
    if (n == 0)
        return 0;
    if(n==0 && k==0) return 1;
  
  if (dp[n- 1][k] != -1)
        return dp[n - 1][k];

    // If last element is greater than k,then ignore it
    if (arr[n - 1] > k)
        return dp[n - 1][k]=subsetsum( n-1,k,arr,dp);
  
    /* else, check if k sum possible by including the last element or excluding the last element   */
    return dp[n - 1][k]=subsetsum( n-1, k, arr,dp)||subsetsum( n-1, k-arr[n-1],arr,dp);
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<int>> dp(n+1,vector<int> (k+1,-1));
    if(subsetsum(n,k,arr,dp))
        return true;
    return false;
}

//recursive
/*
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    // base case
    if (k== 0 )
        return true;
    if (n == 0)
        return false;
  
    // If last element is greater than k,then ignore it
    if (arr[n - 1] > k)
        return subsetSumToK( n-1,k,arr);
  
    //else, check if k sum possible by including the last element or excluding the last element   
    return subsetSumToK( n-1, k, arr) || subsetSumToK( n-1, k-arr[n-1],arr);
}
*/
