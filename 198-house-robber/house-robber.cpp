class Solution {
public:
    int find(int indx,vector<int>&nums,vector<int>&dp){
        if(indx==0) return nums[0];
        if(indx<1) return 0;
        if(dp[indx]!=-1) return dp[indx];
        int pick=nums[indx]+find(indx-2,nums,dp);
        int notpick=0+find(indx-1,nums,dp);
        return dp[indx]=max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        //memoization based approach
        int n=nums.size();
        vector<int>dp(n,-1);
        return find(n-1,nums,dp);
    }
};