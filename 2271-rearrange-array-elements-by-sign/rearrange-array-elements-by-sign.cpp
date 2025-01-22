class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int negativepos=1;
        int positivepos=0;
        vector<int>num(nums.size());
        for(auto el:nums){
            if(el<0){
                num[negativepos]=el;
                negativepos+=2;
            }else{
                num[positivepos]=el;
                positivepos+=2;
            }
        }
        return num;
    }
};