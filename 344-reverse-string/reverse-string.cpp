class Solution {
public:
    void reverseString(vector<char>& s) {
        // stack<char> st;
        // for(auto ch:s){
        //     st.push(ch);
        // }
        // int n=s.size();
        // for(int i=0;i<n;i++){
        //     s[i]=st.top();
        //     st.pop();
        // }
        int i=0,j=s.size()-1;
        while(i<j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
    }
};