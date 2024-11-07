class Solution {
   
   
    public int fib_rec(int n) {

        if(n<=1)return n;

        return fib_rec(n-1)+fib_rec(n-2);
        
    }

    public int fib_memo(int n , int dp[]) {

        if(n<=1)return n;

        if(dp[n]!=-1) return dp[n]; // checking if we already calculated the values or not 

        return dp[n] = fib_memo(n-1, dp)+fib_memo(n-2, dp); // stroing the answer
        
    }



    public int fib(int n) {
        //n=1;
        if(n<=1)return n; // 

        // conversion to memoziation
        //1. array bana 

        int dp[] = new int[n+1]; // first step - 1 extra 

        // 2nd step ka fill -1 
        Arrays.fill(dp,-1);

 
        // base case handle 

        dp[0] = 0;
        dp[1] = 1;

        for(int i = 2 ; i<=n ; i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
        
    }



}