class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0;
        int  i=0;
        int high=nums.size()-1;
        while(i<=high){
            if(nums[i]==0){
                swap(nums[i],nums[low]);
                low++;
                i++;
            }

        else if(nums[i]==2){
            swap(nums[i],nums[high]);
            high--;
            // i++;
        }
        else{i++;};
    }}
};