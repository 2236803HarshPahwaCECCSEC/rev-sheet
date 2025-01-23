class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // if(nums.size()==1){return ;}
        // vector<int>temp;
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]!=0){
        //         temp.push_back(nums[i]);
        //     }
        // }
        // int nz=temp.size();
        // for(int i=nz;i<nums.size();i++){
        //     temp.push_back(0);
        // }
        // for(int i=0;i<nums.size();i++){
        //     nums[i]=temp[i];
        // }
        if(nums.size()==1) return;
        int i=0;
        int j=0;
        for(;j<nums.size();j++){
            if(nums[j]!=0){
                swap(nums[j],nums[i]);
                i++;
            }
        }
        // return nums;


    }
    
};