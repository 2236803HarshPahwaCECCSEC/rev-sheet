class Solution {
public:
    vector<int>nextsmallerindices(vector<int>&heights,int n){
        vector<int>result(n);
        stack<int>st;
        st.push(-1);
        for(int i=n-1;i>=0;i--){
            while(st.top()!=-1 && heights[st.top()]>=heights[i]){
                st.pop();
            }
            result[i]=st.top();
            st.push(i);
        }
        return result;
    }
    vector<int> prevsmallerindices(vector<int>heights,int n){
        vector<int>result(n);
        stack<int> st;
        st.push(-1);
        for(int i=0;i<n;i++){
            while(st.top()!=-1&&heights[st.top()]>=heights[i]){
                st.pop();
            }
            result[i]=st.top();
            st.push(i);
        }
        return result;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>next(n);
        next=nextsmallerindices(heights,n);
        vector<int>prev(n);
        prev=prevsmallerindices(heights,n);
        int maxArea=INT_MIN;
        for(int i=0;i<n;i++){
            int curr=heights[i];
            if(next[i]==-1){
                next[i]=n;//this states that no smaller element on the right of the present case;
            }
            int l_index=prev[i];
            int r_index=next[i];
            int width=r_index-l_index-1;
            int currarea=curr*width;
            maxArea=max(maxArea,currarea);
        }
        return maxArea;
    }
};