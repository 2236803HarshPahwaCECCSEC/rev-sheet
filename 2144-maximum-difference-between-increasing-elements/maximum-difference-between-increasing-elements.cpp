class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        // int maxdiff=0; brute force approach
        
        // for(int i=0;i<nums.size();i++){
        //     int diff=0;
        //     for(int j=i+1;j<nums.size();j++){
        //         if(nums[i]<nums[j]){
        //             diff=nums[j]-nums[i];
        //             maxdiff=max(maxdiff,diff);
        //         }
        //     }
            
        // }
        // return (maxdiff>0)?maxdiff:-1; 


        int minVal=nums[0];
        int maxdiff=-1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>minVal){
                maxdiff=max(maxdiff,nums[i]-minVal);
            }else{
                minVal=nums[i];
            }
        }
        return maxdiff;
    }
};