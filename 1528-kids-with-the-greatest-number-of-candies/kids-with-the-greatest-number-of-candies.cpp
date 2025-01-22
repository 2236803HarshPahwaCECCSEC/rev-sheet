class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> res;
        int maxel=*max_element(candies.begin(),candies.end());
        for(auto el:candies){
            int sum=el+extraCandies;
            if(sum>=maxel){
                res.push_back(true);
            }else res.push_back(false);
            
        }
        return res;
    }
};