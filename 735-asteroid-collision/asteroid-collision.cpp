class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(auto &a:asteroids){
            while(!st.empty()&&st.top()>0&&a<0){
                int sum=st.top()+a;
                if(sum<0){
                    st.pop();
                }
                else if(sum>0){
                    a=0;
                }else{//sum==0
                    st.pop();
                    a=0;
                }
            }
            if(a!=0) st.push(a);
        }
        int size=st.size();
        vector<int>result(size);
        int i=size-1;
        while(!st.empty()){
            result[i]=st.top();
            st.pop();
            i--;
        }
        return result;
    }
};