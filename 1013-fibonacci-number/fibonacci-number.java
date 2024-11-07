class Solution {
   
   
    public int fib_rec(int n) {

        if(n<=1)return n;

        return fib_rec(n-1)+fib_rec(n-2);
        
    }

    public int fib(int n) {

        return fib_rec(n);
        
    }



}