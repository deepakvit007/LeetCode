class Solution
{
    public:
        // void solve(int index, int k, vector<int> op ,int &ans)
        // {
        //     if (op.size() == 1)
        //     {
        //         ans= op[0];
        //         return;
        //     }
        //     index = (index + k) % op.size();
        //     op.erase(op.begin() + index);
        //     solve(index, k, op,ans);
        // }

    int findTheWinner(int n, int k)
    {
        // vector<int> op;
        // for (int i = 1; i < n + 1; i++) op.push_back(i);
        // k--;
        // int ans=-1;
        // solve(0, k, op,ans);
        // return ans;
            int index=0;
        for(int i=1;i<=n;++i){
        index = (index+k)%i;
    }
        return index+1;
      }
};