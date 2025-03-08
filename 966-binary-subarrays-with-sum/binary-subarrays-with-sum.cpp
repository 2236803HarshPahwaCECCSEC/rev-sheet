class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int k) {
        // int n=nums.size();//brute force approach
        // int count=0;
        // for(int i=0;i<n;i++){
        //     int sum=0;
        //     for(int j=i;j<n;j++){
        //         sum+=nums[j];
        //         if(sum==k)count++;
        //     }
        // }
        // return count;

        //prefix sum approach based on map
        // map<int,int>mp;
        // int sum=0,result=0;
        // mp[0]=1;
        // int n=nums.size();
        // for(int i=0;i<n;i++){
        //     sum+=nums[i];
        //     int remaining_sum=sum-k;
        //     if(mp.find(remaining_sum)!=mp.end()){
        //         result+=mp[remaining_sum];
        //     }
        //     mp[sum]++;
        // }
        // return result;
        int i=0,j=0;
        int result=0,count_zeroes=0;
        int sum=0;
        int n=nums.size();
        while(j<n){
            sum+=nums[j];
            while(i<j&&(nums[i]==0||sum>k)){
                if(nums[i]==0) count_zeroes++;
                else count_zeroes=0;
                sum-=nums[i];
                i++;
            }
            if(sum==k){
                result+=(1+count_zeroes);
            }
            j++;
        }
        return result;
    }
};