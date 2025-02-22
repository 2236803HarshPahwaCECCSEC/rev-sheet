class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // int n=nums.size();tle
        // k=k%n;
        // while(k--){
        //     int prev=nums[n-1];
        //     for(int i=n-1;i>0;i--){
        //         nums[i]=nums[i-1];
        //     }
        //     nums[0]=prev;
        // }
        int n=nums.size();
        // k=k%n;
        // reverse(nums.begin(),nums.end());
        // reverse(nums.begin(),nums.begin()+k);
        // reverse(nums.begin()+k,nums.end());

        vector<int>temp;
        k=k%n;
        for(int i=n-k;i<n;i++){
            temp.push_back(nums[i]);
        }
        for(int i=0;i<n-k;i++){
            temp.push_back(nums[i]);
        }
        nums=temp;
    }
};