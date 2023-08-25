class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_so_far = prices[0];
        int max_profit = INT_MIN;

        for(int i=0;i<prices.size();i++)
        {
            int curr_profit  = prices[i] - min_so_far;
            min_so_far = min(min_so_far,prices[i]);
            
            max_profit = max(max_profit,curr_profit);
        }
        return max_profit;
    }
};