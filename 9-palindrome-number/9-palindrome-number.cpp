class Solution {
public:
 bool isPalindrome(int x) {
        
        long temp=x,res=0,digit;
        
        while(x>0)
        {
            digit=x%10;
            res=res*10+digit;
            x=x/10;
            
        }
        if(res==temp)
            return true;
        else
            return false;
        
    }
};