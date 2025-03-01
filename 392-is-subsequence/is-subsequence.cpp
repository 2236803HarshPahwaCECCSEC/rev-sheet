class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s=="") return true; 
        if(t=="") return false;
        int s_index=0;
        int t_index=0;
        while(t_index<t.length()){
            if(s[s_index]==t[t_index]){
                s_index++;
                if(s_index==s.length()){
                    return true;
                }
            }
            t_index++;
        }
        return false;
    }
};