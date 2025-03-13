class Solution {
public:
    int ansUsingRecursion(vector<int>&coins,int amount){
        if(amount==0)return 0;
        int mini=INT_MAX;
        for(int i=0;i<coins.size();i++){
            if(amount-coins[i]>=0){
                int ans=ansUsingRecursion(coins,amount-coins[i]);
                if(ans!=-1){
                    mini=min(1+ans,mini);
                }
            }
        }
        return (mini==INT_MAX)?-1:mini;
    }
    int usingmemo(vector<int>& coins, int amount,vector<int>&dp){
        if(amount==0) return 0;
        if(dp[amount]!=-1) return dp[amount];
        int mini=INT_MAX;
        for(int i=0;i<coins.size();i++){
            if(amount-coins[i]>=0){
                int check=usingmemo(coins,amount-coins[i],dp);
                if(check!=INT_MAX){
                    mini=min(1+check,mini);
                }
            }
        }
            dp[amount] =mini; // Memoize the result
    return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        // return ansUsingRecursion(coins,amount);
        vector<int>dp(amount+1,-1);
        if(usingmemo(coins,amount,dp)==INT_MAX) return -1;
        else return usingmemo(coins,amount,dp); 
    }
};