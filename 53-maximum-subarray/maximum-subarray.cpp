class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // if(nums.size()==0) return 0;
        long long sum=0,maxSum=LONG_MIN;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(maxSum<sum) maxSum=sum;
            if(sum<0) sum=0;
        }
        return maxSum;
    }
};