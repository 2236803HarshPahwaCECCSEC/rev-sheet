class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        // bool res=false;
        for(int i=0;i<s2.length();i++)
        {
            for(int j=i;j<s2.length();j++){
                swap(s2[i],s2[j]);
                if(s1==s2) return true;
                else swap(s2[i],s2[j]);
            }
         }
         return false;
    }
};