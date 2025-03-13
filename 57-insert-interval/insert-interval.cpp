class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> temp=intervals;
        temp.push_back(newInterval);
        sort(temp.begin(),temp.end());
        int i=0;
        int n=temp.size();
        vector<vector<int>>result;
        while(i<n){
            int start=temp[i][0];
            int end=temp[i][1];
            i+=1;
            while(i<n&&end>=temp[i][0]){
                end=max(end,temp[i][1]);
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