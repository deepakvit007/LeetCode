class Solution {
public:
    int maxProfit(vector<int>&arr) {
        
        int n=arr.size();
        int minsofar=arr[0];
        int maxprofit=0;
        for(int i=0;i<n;i++)
        {
            minsofar=min(arr[i],minsofar);
            
            maxprofit=max(arr[i]-minsofar,maxprofit);
            
        }
        
        return maxprofit;
    }
};