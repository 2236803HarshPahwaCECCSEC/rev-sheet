class Solution {
public:
    int maxVowels(string s, int k) {
        int length=0;
        int maxlength=INT_MIN;
        int window_start=0;
        for(int i=0;i<k;i++){
            if(s[i]=='a'||s[i]=='o'||s[i]=='e'||s[i]=='i'||s[i]=='u') length++;
        }
        maxlength=max(maxlength,length);
        for(int i=k;i<s.size();i++){
            if(s[i-k]=='a'||s[i-k]=='o'||s[i-k]=='e'||s[i-k]=='i'||s[i-k]=='u') length--;
            if(s[i]=='a'||s[i]=='o'||s[i]=='e'||s[i]=='i'||s[i]=='u') length++;
            maxlength=max(maxlength,length);
        }
        return maxlength;
    }

};