class Solution {
public:
    bool search(vector<int>& nums, int target) {
         int start = 0;
     int end = nums.size()-1;
    
            while(start <= end)   
            {
                int mid = (start+end)/2;
                if(nums[mid]== target) return true;

                while(nums[mid] == nums[start] and start != mid) start++;
                while(nums[mid] == nums[end] and end != mid) end--;

                if(nums[start] <= nums[mid])
                    (target>=nums[start] and target<nums[mid]) ? end = mid-1 : start = mid+1;
                else
                    (target<=nums[end] and target>nums[mid]) ? start = mid+1 : end = mid-1;
            }

        return false;
        
        
    }
};