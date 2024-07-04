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
        if (n == 1) return 5;

        long long evenPlace = 0;
        long long oddPlace = 0;
        if (n % 2 == 1)
        {
            oddPlace = n / 2;
            evenPlace = n / 2 + 1;
        }
        else
        {
            oddPlace = n / 2;
            evenPlace = n / 2;
        }

        return (pow(5, evenPlace) *pow(4, oddPlace)) % mod;
    }
};