class Solution {
public:
    // int calculate(int n,vector<int>&dp){
    //     if(n==0||n==1){
    //         return 1;
    //     }
    //     if(dp[n]!=-1) return dp[n];
    //     return dp[n]=calculate(n-1,dp)+calculate(n-2,dp);
    // }
    int climbStairs(int n) {
        // vector<int> dp(n+1,-1);
        // return calculate(n,dp);
        if(n==0||n==1) return 1;
        int prev=1;
        int prev1=1;
        for(int i=2;i<=n;i++){
            int val=prev+prev1;
            prev=prev1;
            prev1=val;
        }
        return prev1;
    }
};