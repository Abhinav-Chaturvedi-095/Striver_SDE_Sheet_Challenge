int knapsack(vector<int>& values, vector<int>& weights, int n,int w,vector<vector<int>>& dp){
    //base case
    if(n==0 || w == 0)
        return 0;
    if (dp[n][w]!=-1)
        return dp[n][w];

    // if n weight more than w then not included
    if(weights[n-1]>w)
        return dp[n][w]=knapsack(values,weights,n-1,w,dp);
   //max(when included,when not included)
    else
        return dp[n][w]=max(values[n-1] + knapsack(values,weights,n-1,w-weights[n-1],dp),knapsack(values,weights,n-1,w,dp));
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	// Write your code here
    vector<vector<int>> dp(n+1,vector<int> (w+1,-1)); 
    return knapsack(values,weights,n,w,dp);
    
}

//recursive solution
/*
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
    // Write your code here
    //base case
    if(n==0 || w == 0)
        return 0;
    // if n weight more than w then not included
    if(weights[n-1]>w)
        return maxProfit(values,weights,n-1,w);
   //max(when included,when not included)
    else
        return max(values[n-1] + maxProfit(values,weights,n-1,w-weights[n-1]),maxProfit(values,weights,n-1,w));
}
*/
