class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k == nums.size())
        {
            int maxm = *max_element(nums.begin(),nums.end());
            return {maxm};
        }

        int fixed = 0;
        int move = 0;
        deque<int>dq;
        vector<int>ans;
        while(move<nums.size())
        {
            while(!dq.empty() and dq.back()<nums[move])
            dq.pop_back();
            

            dq.push_back(nums[move]);

            if(move - fixed + 1 < k)
            {
                move++;   
            }
            else if(move - fixed + 1 == k)
            {
                  ans.push_back(dq.front());

                  if(dq.front() == nums[fixed])dq.pop_front();

                  move++;
                  fixed++;
            }
        }

        return ans;
    }
};