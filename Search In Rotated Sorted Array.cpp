int search(int* nums, int n, int target) {
    int low = 0 , high = n - 1;
        while(low<=high)
        {
            if(nums[low]==target)
                return low;
            else if(nums[high]==target)
                return high;
            int mid = low + (high-low)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]<target)
            {
                if(target>nums[0] && nums[mid]<nums[0]) high=mid -1;
                else low = mid + 1;
            }
            else if(nums[mid]>target)
            {
                if(target<nums[0] && nums[mid]>nums[0]) low = mid + 1;
                else high = mid - 1;
            }
        }
        return -1;
}
