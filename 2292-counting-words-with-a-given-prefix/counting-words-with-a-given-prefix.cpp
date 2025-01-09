class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n=words.size();
        int count=0;
        int sizeofpref=pref.length();
        for(int i=0;i<n;i++){
            string str=words[i];
            if(str.substr(0,sizeofpref)==pref) count++;
        }
        return count;
    }
};