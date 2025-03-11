class Solution {
public:
   
    int numberOfSubstrings(string s) {
        int count=0;
        int n=s.length();
        vector<int>freq(3,0);//0->a,1->b,2->c
        int i=0,j=0;
        while(j<n){
            char ch=s[j];
            freq[ch-'a']++;
            while(freq[0]>0&&freq[1]>0&&freq[2]>0){
                count+=n-j;
                char leftchar=s[i];
                freq[leftchar-'a']--;
                i++;

            }
            j++;
        }
        return count;
    }
};