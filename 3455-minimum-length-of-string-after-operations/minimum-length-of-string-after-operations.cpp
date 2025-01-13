class Solution {
public:
    int minimumLength(string s) {
        int length=s.length();
        vector<int>freq(26);
        for(int i=0;i<length;++i){
            freq[s[i]-'a']++;
        }
        int res=0;
        for(int i=0;i<26;++i){
            if(freq[i]&1) res+=1;
            else res+=min(2,freq[i]);
        }
        return res;
    }
};