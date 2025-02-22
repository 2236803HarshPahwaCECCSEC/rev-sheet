class Solution {
public:
    // int fibonacci(int n,vector<int>&dp){ Memomization approach
    //     if(n<=1) return n;
    //     if(dp[n]!=-1) return dp[n];
    //     dp[n]=fibonacci(n-1,dp)+fibonacci(n-2,dp);
    //     return dp[n];
    // }
    int fib(int n) {
        // if(n==0) return 0;
        // if(n==1) return 1;
         
        // return fib(n-1)+fib(n-2);
        // vector<int>dp(n+1,-1);
        // return fibonacci(n,dp);
        // vector<int>dp(n+1,-1);
        // dp[0]=0;
        // dp[1]=1;
        // for(int i=2;i<=n;i++){
        //     dp[i]=dp[i-1]+dp[i-2];
        // }
        // return dp[n];
        if(n<=1) return n;
        int prev=0;
        int prev1=1;
        for(int i=2;i<=n;i++){
            int val=prev+prev1;
            prev=prev1;
            prev1=val;
        }
        return prev1;

    }
};