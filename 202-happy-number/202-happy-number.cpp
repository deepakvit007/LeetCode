
class Solution {
public:
    bool isHappy(int n) {
        
        map<int,int>mp1;
        int sum=n;
        mp1[n]++;
        while(true){
            int t=n,te=0;
            while(t>0){
                int x=t%10;
                te+=x*x;
                t/=10;
            }
            if(te==1){
                return true;
            }
            
            mp1[te]++;
            
            if(mp1[te]>1){
                return false;
            }
            n=te;
        }
    }
};