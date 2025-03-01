class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // vector<int>result(nums.size());//brute force tle
        // for(int i=0;i<nums.size();i++){
        //     int product=1;
        //     for(int j=0;j<nums.size();j++){
        //         if(i!=j){
        //             product*=nums[j];
        //         }
        //     }
        //     result[i]=product;
        // }
        // return result;
        // int n=nums.size();//o(n) sc o(n)
        // vector<int> prefix(n,1),suffix(n,1),output(n);
        // for(int i=1;i<n;i++){
        //     prefix[i]=prefix[i-1]*nums[i-1];
        // }
        // for(int i=n-2;i>=0;i--){
        //     suffix[i]=suffix[i+1]*nums[i+1];
        // }
        // for(int i=0;i<n;i++){
        //     output[i]=prefix[i]*suffix[i];
        // }
        // return output;

        //most efficient approach TC o(n) SC o(1)
        int n=nums.size();
        vector<int>output(n,1);
        int prefix=1;
        for(int i=0;i<n;i++){
            output[i]*=prefix;
            prefix*=nums[i];
        }
        int suffix=1;
        for(int i=n-1;i>=0;i--){
            output[i]*=suffix;
            suffix*=nums[i];
        }
        return output;
    }
};