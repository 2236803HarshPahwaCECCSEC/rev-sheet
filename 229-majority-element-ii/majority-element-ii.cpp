class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //boyer moore voting majority algo O(1) space complexity
        int candidate1=0,candidate2=0;
        int count1=0,count2=0;
        for(int num:nums){
            if(count1==0&&num!=candidate2){
                candidate1=num;
                count1=1;
            }
            else if(count2==0&&num!=candidate1){
                candidate2=num;
                count2=1;
            }
            else if(num==candidate1) count1++;
            else if(num==candidate2) count2++;
            else {
                count1--;
                count2--;
            }
        }
        //verification starts

        count1=count2=0;
        for(auto num:nums){
            if(num==candidate1) count1++;
            else if(num==candidate2) count2++;
        }
        int n=nums.size();
        vector<int>res;
        if(count1>n/3) res.push_back(candidate1);
        if(count2>n/3) res.push_back(candidate2);

        return res;

        //brute force approach with hash map
        // unordered_map<int,int> mp;
        // for(auto num:nums){
        //     mp[num]++;
        // }
        // vector<int> res;
        // int n=nums.size();
        // for(auto pair:mp){
        //     if(pair.second>(n/3)){
        //         res.push_back(pair.first);
        //     }
        // }
        // return res;
    }
};