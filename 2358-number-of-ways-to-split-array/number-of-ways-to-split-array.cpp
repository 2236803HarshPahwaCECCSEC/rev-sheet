class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        long long res=0;
        vector<long long>pre(n,0);//for storing prefix sum
        pre[0]=nums[0];
        for(int i=1;i<n;i++){
            pre[i]=nums[i]+pre[i-1];
        }
        long long totalsum=pre[n-1];
        for(int i=0;i<n-1;i++){
            if(pre[i]>=(totalsum-pre[i])){
                res++;
            }
        }
        return (int)res;
    }
};