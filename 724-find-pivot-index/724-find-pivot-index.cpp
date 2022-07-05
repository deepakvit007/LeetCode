class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int sum = accumulate(nums.begin(),nums.end(),0);

        int left=0;
        int right = sum;
        
        for(int i=0;i<nums.size();i++)
        {
          right=right-nums[i];
            
            if(left==right)
                return i;
            
            left=left+nums[i];
            
            
        }
        return -1;
    }
};