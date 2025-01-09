class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                if(sum==k)count++;
            }
        }
        return count;
        // int n=nums.size();
        // int l=0;
        // int r=0;
        // int count=0;
        //     int sum=0;

        // while(r<n){
        //     sum+=nums[r];
        //     while(sum>k&&l<=r){
        //         sum-=nums[l];
        //         l=l+1;
        //     }
        //     if(sum==k) count++;
        //     r=r+1;
        // }
        // return count;
    }
};