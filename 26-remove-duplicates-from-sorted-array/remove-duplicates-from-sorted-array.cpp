class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int j=0;
        int i=0;
        for( i = 1;i<nums.size();i++)
        {
            if(nums[i]!=nums[i-1])
            {
                nums[j++]=nums[i-1];
            }
        }
        nums[j++]=nums[i-1];
        return j;
    }
};