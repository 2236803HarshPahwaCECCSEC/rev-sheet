class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int posword1=0;
        int posword2=0;
        string res="";
        while(posword1<word1.length()||posword2<word2.length()){
            if(posword1<word1.length()) res+=word1[posword1++];
            if(posword2<word2.length()) res+=word2[posword2++];

        }
        return res;
    }
};