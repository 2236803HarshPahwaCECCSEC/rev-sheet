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
    int usingTabu(vector<int>& coins,int amount){
        vector<int>dp(amount+1,INT_MAX);
        dp[0]=0;//base case when amount is 0 coins choosen would be zero
        for(int value=1;value<=amount;value++){
        int mini=INT_MAX;
            for(int i=0;i<coins.size();i++){
                if(value-coins[i]>=0){
                    int ans=dp[value-coins[i]];
                    if(ans!=INT_MAX){
                        int result=1+ans;//choose this coin and the previous value term
                        mini=min(mini,result);
                    }
                }
            }
            dp[value]=mini;
        }
        return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        // return ansUsingRecursion(coins,amount);
        // vector<int>dp(amount+1,-1);
        if(usingTabu(coins,amount)==INT_MAX) return -1;
        else return usingTabu(coins,amount); 
    }
};