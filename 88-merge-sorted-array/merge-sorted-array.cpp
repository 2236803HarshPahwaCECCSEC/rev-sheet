class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    //    if(n==0) return;
    //    if(m==0) nums1=nums2;  
    //    int i=m-1;
    //    int j=n-1;
    //    int k=m+n-1;
    //    while(i>=0&&j>=0){
    //     if(nums1[i]>nums2[j]){
    //         nums1[k]=nums1[i];
    //         k--;
    //         i--;
    //     }else{//nums[i]<nums[j]
    //         nums1[k]=nums2[j];
    //         k--;
    //         j--;
    //     }
    //    }
    //    while(j>=0){//there will be cases where we need to handle for nums1[i]>nums2[j]
    //     nums1[k]=nums2[j];
    //     k--;
    //     j--;
    //    }
    copy(nums2.begin(),nums2.end(),nums1.begin()+m);
    sort(nums1.begin(),nums1.end()); 
    }
};