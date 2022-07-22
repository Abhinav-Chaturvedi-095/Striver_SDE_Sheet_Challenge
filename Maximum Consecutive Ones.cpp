int longestSubSeg(vector<int> &nums , int n, int k){
    // Write your code here.
    int left = 0, ans = 0, cntZeros = 0;
        for (int right = 0; right < nums.size(); ++right) {
            if (nums[right] == 0) ++cntZeros;
            while (cntZeros > k) { 
 // nums[left, right] contains more than k zeros, move left util the subarray has no more than k zeros
                if (nums[left] == 0) --cntZeros;
                ++left;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
}
//sliding window
