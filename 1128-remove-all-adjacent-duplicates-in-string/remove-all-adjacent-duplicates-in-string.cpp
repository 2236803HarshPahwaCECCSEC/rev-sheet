class Solution {
public:
    string removeDuplicates(string s) {
        string res;
        stack<char>st;
        char ch=s[0];
        st.push(ch);
        for(int i=1;i<s.size();i++){
            ch=s[i];
            if(!st.empty()&&st.top()==ch){
                st.pop();
            }else{st.push(ch);}
        }
       while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};