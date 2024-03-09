class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>maxh;
        //priority_queue<int,vector<int>,greater<int>>minh;
        for(auto s : nums){
            maxh.push(s);
        }

        while(--k)
        {
              maxh.pop();
        }

        return maxh.top();
    }
};