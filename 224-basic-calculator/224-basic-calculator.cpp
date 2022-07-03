class Solution {
public:
    int calculate(string s) {
        
        int sign=1;//for calculating subtraction
        
        int sum=0;
        
        stack<int>st;
        
        for(int i=0;i<s.size();i++)
        {
            
            if(s[i]>='0' && s[i]<='9')
            {
                int num=0;
                    while(i<s.size() && s[i]>='0' && s[i]<='9')
                    {
                        num = num*10+(s[i]-'0');
                        i++;               
                    }
                  sum=sum + sign*num;
                  i--;
            }
            else if(s[i]=='+')sign=1;
            else if(s[i]=='-')sign=-1;
            else if(s[i]=='(')
            {
                st.push(sum);
                st.push(sign);
                sign=1;
                sum=0;
            }
            else if(s[i]==')')
            {
                sign=st.top();st.pop();
                int prevSum=st.top();st.pop();
                sum=sign*sum;
                sum=sum+prevSum;
               
            }
        }
        return  sum;
        
    }
};