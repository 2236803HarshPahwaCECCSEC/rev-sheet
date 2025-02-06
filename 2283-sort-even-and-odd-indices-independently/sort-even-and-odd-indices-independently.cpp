class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        if(nums.size()==0) return nums;
        vector<int> even_index,odd_index;
        for(int i=0;i<nums.size();i++){
            if(i%2==0) even_index.push_back(nums[i]);
            else odd_index.push_back(nums[i]);
        }
        sort(even_index.begin(),even_index.end());
        sort(odd_index.begin(),odd_index.end(),greater<int>());
        for(int i=0,j=0,k=0;i<nums.size();i++){
            if(i%2==0){nums[i]=even_index[j++];}
            else nums[i]=odd_index[k++];
        }
        return nums;
    }
};