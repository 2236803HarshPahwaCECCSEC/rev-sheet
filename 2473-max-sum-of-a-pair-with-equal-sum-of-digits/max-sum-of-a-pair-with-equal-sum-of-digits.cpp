class Solution {
public:
    int calculatedigitsum(int num){
        int temp=num;
        int sum=0;
        while(temp!=0){
            sum+=temp%10;
            temp=temp/10;
        }
        return sum;
    }
    // int maximumSum(vector<int>& nums) {
    //     int sum=0,maxSum=0;
    //     // sort(nums.begin(),nums.end());
    //     for(int i=0;i<nums.size();i++){
    //         for(int j=i+1;j<nums.size();j++){
    //             int num1=nums[i];
    //             int num2=nums[j];
    //             int sumdigitsnum1=calculatedigitsum(num1);
    //             int sumdigitsnum2=calculatedigitsum(num2);
    //             if(sumdigitsnum1==sumdigitsnum2){
    //                 sum=num1+num2;
    //             }
    //         }
    //         maxSum=max(sum,maxSum);
    //         sum=0;
    //     }
    //     return maxSum>0?maxSum:-1;
    // }
    int maximumSum(vector<int>& nums) {
        unordered_map<int,vector<int>> mp;
        int sum=0,maxSum=0;
        sort(nums.begin(),nums.end());
        for(auto num:nums){
            int digitsum=calculatedigitsum(num);
            mp[digitsum].push_back(num);
        }    
        for(auto pair:mp){
            vector<int> v=mp[pair.first];
            if(v.size()>=2){
            sum+=v[v.size()-1]+v[v.size()-2];
            maxSum=max(maxSum,sum);
            }
            sum=0;
        }
        
        return maxSum>0?maxSum:-1;
    }
};