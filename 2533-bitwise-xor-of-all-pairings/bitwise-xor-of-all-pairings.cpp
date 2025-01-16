class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        // vector<int>nums3;
        int xorval=0;
        // for(int i=0;i<nums1.size();i++){
        //     for(int j=0;j<nums2.size();j++){
        //          xorval^=(nums1[i]^nums2[j]);
        //         // nums3.push_back(xorval);
        //     }
        // }
        if(nums1.size()%2==1){
            for(auto& num:nums2){
                xorval^=num;
            }
        }
        if(nums2.size()%2==1){
            for(auto&num:nums1){
                xorval^=num;
            }
        }
        return xorval;
    }
};