class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int zero=0;
        int start=1;

        while(start<nums.size() and zero<=start)
        {
            if(nums[zero] == 0 and nums[start]!=0)
            {
                swap(nums[zero],nums[start]);
                zero++;
                start++;
            }
            else if(nums[zero]==0 and nums[start] == 0)
            {
               start++;
            }
            else if(nums[zero]!=0 and nums[start] == 0)
            {
                zero++;
            }
            else
            {
                start++;
            }

        }
    }
};