#include <bits/stdc++.h> 
vector<vector<int>> pairSum(vector<int> &nums, int s){
   // Write your code here.
         vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        vector<int>temp(2,0);
        int n=nums.size();
        for(int i=0;i<n;i++){
            int x=s-nums[i];
                for(int j=i+1;j<n;j++){
                    if(nums[j]==x) {
                        temp[0]=nums[i];
                        temp[1]=nums[j];
                        ans.push_back(temp);
                    }
                }
        }
        return ans;
}
