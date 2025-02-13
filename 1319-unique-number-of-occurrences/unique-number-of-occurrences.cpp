class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(auto num:arr){
            mp[num]++;
        }
        set<int> s;
        bool result=true;
        for(auto m:mp){
            int val=m.second;
            auto x=s.find(val);
            if(x!=s.end()){
                result=false;
                break;
            }
            s.insert(val);
           
        }
        return result;
    }
};