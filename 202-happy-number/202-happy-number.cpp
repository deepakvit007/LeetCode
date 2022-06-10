class Solution {
public:
    int help(int n)
    {
        int dig,ans=0;
        while(n>0)
        {
           dig=n%10;
            ans=ans+dig*dig;
            n=n/10;
            
        }
        return ans;
    }
    
    bool isHappy(int n) {
        
        int slow=n,fast=n;
        
        
        do
        {
            slow=help(slow);
            fast=help(help(fast));
            n=slow;
            if(fast==1)return true;
            
        }while(slow!=fast);
        
        return false;
        
        
        
    }
};