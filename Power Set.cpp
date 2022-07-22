vector<vector<int>> pwset(vector<int>v)
{
    //Write your code here
    vector<vector<int>> ans;
    int n = v.size();

    ans.push_back({});

    for(int i=0; i<n; i++)
    {
        int sz = ans.size();
        for(int j=0; j<sz; j++)
        {
            vector<int> temp = ans[j];
            temp.push_back(v[i]);
            ans.push_back(temp);
        }
    }

    return ans;
    
}
