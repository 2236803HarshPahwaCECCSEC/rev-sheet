class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto num:nums){
            mp[num]++;
        }
        vector<int> res;
        int n=nums.size();
        for(auto pair:mp){
            if(pair.second>(n/3)){
                res.push_back(pair.first);
            }
        }
        return res;
    }
};