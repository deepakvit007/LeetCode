class Solution {
public:
   int cal(int a,int b,string op)
    {
        if( op =="+")
        {
            return a + b;
        }
        if(op =="-")
        {
            return b - a;
        }
        if(op =="*")
        {
            return a * b;
        }
        if(op =="/")
        {
            
            return b/a;
        }
        return 0;
    }
    
    int evalRPN(vector<string>& tokens) {
        int n=tokens.size();
        if(n==1) return stoi(tokens[0]);
        if(n<2) return 0;
     stack<string>ans;
        
        int temp1,temp2,res;
        
        
        for(int i=0;i<n;i++)
        {
           
            if(tokens[i]=="+"||tokens[i]=="*"||tokens[i]=="-"||tokens[i]=="/")
            {
                temp1=stoi(ans.top());
                cout<<temp1<<endl;
                ans.pop();
                temp2=stoi(ans.top());
                cout<<temp2<<endl;
                ans.pop();
                res=cal(temp1,temp2,tokens[i]);
                cout<<res<<endl;
                ans.push(to_string(res));
            }
             else
            {
                ans.push(tokens[i]);
            }
            
        }
        int anss=stoi(ans.top());
        
        return anss ;
        
    }
};