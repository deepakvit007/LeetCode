class Solution
{
    public:
        int mod = 1000000007;
    long long pow(long long n, long long k)
    {
        if (k == 0)
        {
            return 1;
        }

        if (k % 2 == 0)
        {
            long long ans = pow(n, k / 2);
            return (ans % mod *ans % mod) % mod;
        }
        else
        {
            long long ans = pow(n, k / 2);
            return (n % mod *ans % mod *ans % mod) % mod;
        }
    }
    int countGoodNumbers(long long n)
    {
        // if (n % 2 == 1)
        // {
        //     oddPlace = n / 2;
        //     evenPlace = n / 2 + 1;
        // }
        // else
        // {
        //     oddPlace = n / 2;
        //     evenPlace = n / 2;
        // }

        long long evenPlace = n/2 + n%2;
        long long oddPlace = n/2;

        return (pow(5, evenPlace) *pow(4, oddPlace)) % mod;
    }
};