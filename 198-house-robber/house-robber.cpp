class Solution {
public:
    int find(int indx,vector<int>&nums,vector<int>&dp){//memoization based
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
        // return find(n-1,nums,dp);

        //tabulation method
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            int take=nums[i];
            if(i>1) take+=dp[i-2];
            int nottake=0+dp[i-1];
            dp[i]=max(take,nottake);
        }
        return dp[n-1];
    }
};