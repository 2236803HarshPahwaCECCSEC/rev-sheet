class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        s+=" ";
        int i;
        string res="";
        for(i=0;i<s.length();i++){
            if(s[i]==' '){
                if(!res.empty())                 st.push(res);
                res="";
            }else
                res+=s[i];
        }
        string str="";
        while(!st.empty()){
            str+=st.top();
            st.pop();
            if(!st.empty()){
                str+=" ";
            }
        }

        return str;
    }
};