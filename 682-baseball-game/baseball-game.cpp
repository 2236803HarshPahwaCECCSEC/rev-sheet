class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>st;
        for(auto str:operations){
            if(str=="+"){
                int top1=st.top();
                st.pop();
                int top2=st.top();
                st.pop();
                st.push(top2);
                st.push(top1);
                st.push(top1+top2);
            }else if(str=="D"){
                int val=st.top();
                st.push(2*val);
            }else if(str=="C"){
                st.pop();
            }else{
                st.push(stoi(str));
            }
        }
        int sum=0;
        while(!st.empty()){
            sum+=st.top();
            st.pop();
        }
        return sum;       
    }
};