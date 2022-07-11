class Solution {
public:
    void solve(int closed,int open, string op ,vector<string>&ans)
    {
        if(closed==0 && open==0)
        {
            ans.push_back(op);
            return;
        }
        
        if(open!=0)
        {
            string op1=op;
            op1.push_back('(');
            solve(closed,open-1,op1,ans);
        }
         if(closed>open)
        {
            string op2=op;
            op2.push_back(')');
            solve(closed-1,open,op2,ans);
        }
        return;
        
        
    }
    
    vector<string> generateParenthesis(int n) {
        
        int closed=n;
        int open=n;
        vector<string>ans;
        string op="";
        solve(closed,open,op,ans);
        return ans;
        
    }
};