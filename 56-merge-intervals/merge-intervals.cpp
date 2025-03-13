class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>result;
        sort(intervals.begin(),intervals.end());
        int i=0;
        int n=intervals.size();
        while(i<n){
            int start=intervals[i][0];
            int end=intervals[i][1];
             i+=1;
            while(i<n&&end>=intervals[i][0]){
                end=max(end,intervals[i][1]);
                i+=1;
            }
            vector<int>temp;
            temp.push_back(start);
            temp.push_back(end);
            result.push_back(temp);
        }
        return result;
    }
};