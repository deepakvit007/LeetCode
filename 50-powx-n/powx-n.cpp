class Solution {
public:

    double pow(double x ,long long n)
    {
        if(n==0)return 1;

        double partialAns = pow(x,n/2);

        if(n%2==1)return x*partialAns*partialAns;

        return partialAns*partialAns;
    }
    double myPow(double x, int n) {
        bool neg = false;
        long long temp = n;
        if(n < 0)
        {
            neg = true;
            temp = -temp;
        }

        double ans = pow(x,temp);

        if(neg == true)
        return 1/ans;

        return ans;
           
    }
};