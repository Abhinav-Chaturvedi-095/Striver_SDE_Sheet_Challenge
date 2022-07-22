void permute(string s, int l, int r,vector<string>&ans) 
{ 
    // Base case 
    if (l == r) 
        ans.push_back(s);
    else
    { 
        // Permutations made 
        for (int i = l; i <= r; i++) { 
            // Swapping done 
            swap(s[l], s[i]);   
            permute(s, l+1, r,ans); 
            //backtrack 
            swap(s[l], s[i]); 
        } 
    } 
} 
  
vector<string> findPermutations(string &s) {
    // Write your code here.
    vector<string> ans;
    int n=s.size();
    permute(s, 0, n-1,ans);
    return ans;
}
