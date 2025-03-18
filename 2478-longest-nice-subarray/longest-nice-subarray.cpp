class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int i=0,j=0;
        int maxLength=0;
        int n=nums.size();
        long long bitwise=0;
        while(j<n){
            while((bitwise & nums[j])!=0){
                bitwise ^= nums[i];
                i++;
            }
            bitwise|=nums[j];
            maxLength=max(maxLength,j-i+1);
            j++;
        }
        return maxLength;
    }
};