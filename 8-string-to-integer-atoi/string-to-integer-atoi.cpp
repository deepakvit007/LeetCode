class Solution
{
    public:
        void solve(string s, int i, int sign, long &temp, int &ans)
        {
            if (sign == -1 and temp > INT_MAX)
            {
                ans = INT_MIN;
                return;
            }
            if (sign == 1 and temp > INT_MAX)
            {
                ans = INT_MAX;
                return;
            }
            if (s[i] >= '0'
                and s[i] <= '9')
            {
                temp = temp *10 + (s[i] - '0');
            }
            else
            {
                ans = sign * temp;
                return;
            }

            solve(s, i + 1, sign, temp, ans);
        }
    int myAtoi(string s)
    {
        int sign = 1;
        int ans = 0;
        int i = 0;

       	//remove whitespaces
        while (i < s.size() and s[i] == ' ') i++;

       	//knowing sign
        if (s[i] == '-')
        {
            sign = -1;
            i++;
        }
        if (s[i] == '+')
        {
            if (sign == -1) return 0;
            i++;
        }

        long temp = 0;
        solve(s, i, sign, temp, ans);

        return ans;
    }
};