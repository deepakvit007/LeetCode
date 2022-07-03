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
                  i--;//our index move one ahead so we are correcting it
            }
            else if(s[i]=='+')sign=1;
            else if(s[i]=='-')sign=-1;
            else if(s[i]=='(')
            {
                //storing our prev sum and sign
                st.push(sum);//pushing sum first
                st.push(sign);//pushing sign 
                
                //restoring the default value
                sign=1;
                sum=0;
            }
            else if(s[i]==')')
            {
                sign=st.top();st.pop();//popping out the sign 
                int prevSum=st.top();st.pop();//popping out the sum that we pushed
                
               // updating our current sum
                sum=sign*sum;
                // adding prevsum to our current sum
                sum=sum+prevSum;
               
            }
        }
        return  sum;
        
    }
};