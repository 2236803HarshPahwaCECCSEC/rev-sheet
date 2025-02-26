class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // if(nums.size()==0) return 0; using kadanes algorithm;
        long long sum=0,maxSum=LONG_MIN;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(maxSum<sum) maxSum=sum;
            if(sum<0) sum=0;
        }
        return maxSum;

        //brute force approach
        // int maxi=INT_MIN;
        // int sum=0;
        // for(int i=0;i<nums.size();i++){
        //     sum=0;
        //     for(int j=i;j<nums.size();j++){
        //         sum+=nums[j];
        //         maxi=max(sum,maxi);
        //     }
        // }
        // return maxi;
    }
};