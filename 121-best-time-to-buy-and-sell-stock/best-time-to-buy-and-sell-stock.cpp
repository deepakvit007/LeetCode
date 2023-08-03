class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int min_so_far = prices[0];
        int max_profit = 0;
        for(int i=1;i<n;i++)
        {
             int profit = prices[i] - min_so_far;

             min_so_far = min(prices[i],min_so_far);

             max_profit = max(max_profit,profit);
        }

        return max_profit;
        
    }
};