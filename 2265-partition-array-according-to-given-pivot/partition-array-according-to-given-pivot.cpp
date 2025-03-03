class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int pivotcount=0;
        vector<int>lessthan;
        vector<int>greaterthan;
        vector<int>result(nums.size());
        for(int i=0;i<nums.size();i++){
            if(nums[i]<pivot) lessthan.push_back(nums[i]);
            else if(nums[i]>pivot) greaterthan.push_back(nums[i]);
            else pivotcount++;
        }
        int i=0;
        for(;i<lessthan.size();i++){
            result[i]=lessthan[i];
        }
        while(pivotcount){
            result[i]=pivot;
            i++;
            pivotcount--;
        }
        for(int j=0;j<greaterthan.size();i++,j++){
            result[i]=greaterthan[j];
        }
        return result;
    }
};