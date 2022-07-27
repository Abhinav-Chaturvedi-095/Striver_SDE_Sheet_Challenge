#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>nums, int n, int K) {
    sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        if(nums.size() == 0) return ans;
        for(int i = 0; i < nums.size() - 1; i++) {
            
            int target = K - nums[i] ;
            int start = i + 1, end = nums.size() - 1 ;
            
            while (start < end) {
                if (nums[start] + nums[end] == target) {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[start]);
                    temp.push_back(nums[end]);
                    ans.push_back(temp);
                    
                    int low = nums[start], high = nums[end] ;
                    while (start < end && nums[start] == low) start++ ;
                    while (start < end && nums[end] == high) end-- ;
                    
                } else if (nums[start] + nums[end] < target){
                    start++ ;
                } else end-- ;
            }
            
            while(i < nums.size() - 1 && nums[i] == nums[i + 1]) i++ ;
        }
        
        return ans ;
}
