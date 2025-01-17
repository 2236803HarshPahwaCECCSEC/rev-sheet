#include<algorithm>
class Solution {
public:
    bool isAnagram(string s, string t) {
        // if(s.length()!=t.length()) return false;
        // sort(s.begin(),s.end());
        // sort(t.begin(),t.end());
        // for(int i=0;i<s.length();i++){
        //     if(s[i]!=t[i]){
        //         return false;
        //     }
        // }
        // return true;


        vector<int> freqtable(256,0);
        for(int i=0;i<s.length();i++){
            freqtable[s[i]]++;
        }
        for(int i=0;i<t.length();i++){
            freqtable[t[i]]--;
        }
        for(int i=0;i<256;i++){
            if(!freqtable[i]==0) return false;
        }
        return true;
    }
};