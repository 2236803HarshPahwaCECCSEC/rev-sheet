class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // vector<int>result;
        // int n=nums.size();
        // if(n==0||k==0) return result;
        // for(int i=0;i<=n-k;i++){
        //     int maxval=nums[i];
        //     for(int j=i;j<i+k;j++){
        //         maxval=max(maxval,nums[j]);
        //     }
        //     result.push_back(maxval);
        // }
        // return result;
        vector<int>result;
        deque<int>dq;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(!dq.empty()&&dq.front()<i-k+1){
                dq.pop_front();
            }
            while(!dq.empty()&&nums[dq.back()]<nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            if(i>=k-1){
                result.push_back(nums[dq.front()]);
            }
        }
        return result;
    }
};