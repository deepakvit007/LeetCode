class Solution {
public:

    void help(vector<int>& tick, int k,int &ans, queue<int>&q)
    {
        

        int indx = q.front();
        q.pop();

        tick[indx]--;
        ans ++;
        if(tick[indx] == 0 and indx == k )return;
        if(tick[indx]>0)q.push(indx);
        help(tick,k,ans,q);

    }
    int timeRequiredToBuy(vector<int>& tick, int k) {

        int n = tick.size();
        queue<int>q;

        for(int i=0;i<n;i++)
        {
            q.push(i);
        }
        int ans=0;
       
       help(tick,k,ans,q);

        return ans;
    }
};