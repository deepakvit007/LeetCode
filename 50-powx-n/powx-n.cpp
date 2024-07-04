class Solution {
public:
    //fast power function
    double pow(double x ,long long n)
    {
        if(n==0)return 1;

        double partialAns = pow(x,n/2);

        if(n%2==1)return x*partialAns*partialAns;

        return partialAns*partialAns;
    }

    double myPow(double x, int n) {

        bool neg = false;

        //making n as long long for handling conversion of -2147483648 into +2147483648
        long long temp = n;

        if(temp < 0)
        {
            neg = true;
            temp = -temp;
        }

        double ans = pow(x,temp);
        
        //handling negative power
        if(neg == true)
        return 1/ans;

        return ans;
           
    }
};