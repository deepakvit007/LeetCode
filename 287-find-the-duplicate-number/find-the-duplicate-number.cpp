class Solution {
public:
     
    void swapSort(vector<int>& nums)
    {
        int i=0;
        int n=nums.size();
        while(i<n)
        {
            int correct = nums[i]-1;

            if(nums[i]!=nums[correct])
            swap(nums[i],nums[correct]);
            else
            i++;
        }
    }
    int findDuplicate(vector<int>& nums) {
        
        int n=nums.size();
        swapSort(nums);
        int ans=n;
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=i+1)
            {
                ans = nums[i];
                break;
            }
        }
       return ans;

    }
};