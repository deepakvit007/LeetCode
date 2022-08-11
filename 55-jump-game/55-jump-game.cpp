class Solution {
public:
    bool canJump(vector<int>& nums) {
          int i;
        int n=nums.size();
        int mx_jmp=nums[0];
        for(i=1;i<=mx_jmp;i++)
        {
             if(i==n)
                break;
            if(nums[i]>0 && i+nums[i]>mx_jmp)
                mx_jmp=nums[i]+i;
        }
        
          if(mx_jmp>=nums.size()-1)
                return true;
        return false;
    }
};