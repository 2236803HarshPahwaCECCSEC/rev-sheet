class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum=0;
        int length=0;
        int minlength=INT_MAX;
        int window_start=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];

            while(sum>=target){
                sum-=nums[window_start];
                minlength=min(minlength,i-window_start+1);

                window_start++;
            }
            
        }
        return minlength==INT_MAX?0:minlength;
    }
};