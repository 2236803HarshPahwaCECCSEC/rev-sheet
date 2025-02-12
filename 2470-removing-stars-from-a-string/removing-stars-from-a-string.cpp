class Solution {
public:
    string removeStars(string s) {
        stack<char>st;
        string res;
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            if(ch!='*'){
                st.push(ch);
            }
            if(ch=='*'){
                st.pop();
            }
        }
        while(!st.empty()){
            char ch=st.top();
            res.push_back(ch);
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};