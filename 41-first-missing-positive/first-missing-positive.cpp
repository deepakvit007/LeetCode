class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
             int i=0;
       while(i<n)
   {      int correct;
          if(nums[i]>0) 
          {correct=nums[i]-1;}
       if( (nums[i] > 0 &&nums[i]<=n )&& nums[i]!=nums[correct] )
       {
           swap(nums[i],nums[correct]);
       }
       else
       {
           i++;
       }
   }
        int j;
        for (j=0;j<n;j++)
    {
        if(nums[j]!=j+1)
            return j+1;
    }
        return n+1;
        
    }
};