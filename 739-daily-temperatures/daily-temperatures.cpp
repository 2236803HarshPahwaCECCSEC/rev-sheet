class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> nextTemp(temperatures.size(),0);
        stack<int> indices;
        for(int i=0;i<temperatures.size();i++){
            while(!indices.empty()&& temperatures[i]>temperatures[indices.top()]){
                int prevIndex=indices.top();
                indices.pop();
                nextTemp[prevIndex]=i-prevIndex;
            }
            indices.push(i);
        }
        return nextTemp;
    }
};