class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int maxdiff=0;
        
        for(int i=0;i<nums.size();i++){
            int diff=0;
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]<nums[j]){
                    diff=nums[j]-nums[i];
                    maxdiff=max(maxdiff,diff);
                }
            }
            
        }
        return (maxdiff>0)?maxdiff:-1;    
    }
};