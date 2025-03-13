class Solution {
    private:
    void nextsmallerelement(vector<int>&nums,vector<int>&next){
        int n=nums.size();
        stack<int>st;
        st.push(-1);
        for(int i=n-1;i>=0;i--){
            while(st.top()!=-1&&nums[st.top()]>=nums[i]){
                st.pop();
            }
            next[i]=st.top();
            st.push(i);
        }
    }
    void prevsmallerelement(vector<int>&nums,vector<int>& prev){
        int n=nums.size();
        stack<int>st;
        st.push(-1);
        for(int i=0;i<n;i++){
            while((st.top()!=-1)&&nums[i]<=nums[st.top()]){
                st.pop();
            }
            prev[i]=st.top();
            st.push(i);
        }
    }
    int histogramArea(vector<int>&nums,int n){
        vector<int>prev(n);
        prevsmallerelement(nums,prev);
        vector<int>next(n);
        nextsmallerelement(nums,next);
        int area=0;
        for(int i=0;i<n;i++){
            if(next[i]==-1) next[i]=n;
            int width=next[i]-prev[i]-1;
            int currarea=nums[i] * width;
            area=max(area,currarea);
        }
        return area;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {//converting this problem to maximal area in histogram
        int rows=matrix.size();
        int cols=matrix[0].size();
        vector<int> heights(cols, 0);
        int maxArea=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(matrix[i][j]!='0'){
                    heights[j]+=1;
                }else{
                    heights[j]=0;
                }
            }
            maxArea=max(maxArea,histogramArea(heights,cols));
        }
        return maxArea;
    }
};