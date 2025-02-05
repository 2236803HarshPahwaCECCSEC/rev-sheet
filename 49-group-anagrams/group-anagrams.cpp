class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //anagram string hoti toh woh h jo rearrange kar ke ek dusre ho jaaye 
        unordered_map<string,vector<string>> anagrams;
        for(auto ch:strs){
            string res=ch;
            sort(res.begin(),res.end());
            anagrams[res].push_back(ch);
        }
        vector<vector<string>> result;
        for(const auto& pair:anagrams){
            result.push_back(pair.second);
        }
        return result;

    }
};