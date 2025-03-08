class Solution {
public:
    int largestAltitude(vector<int>& gains) {
        int n=gains.size();
        vector<int>prefix_sum(n+1);
        prefix_sum[0]=0;
        for(int i=1;i<n+1;i++){
            prefix_sum[i]=prefix_sum[i-1]+gains[i-1];
        }
        return *max_element(prefix_sum.begin(),prefix_sum.end());
    }
};