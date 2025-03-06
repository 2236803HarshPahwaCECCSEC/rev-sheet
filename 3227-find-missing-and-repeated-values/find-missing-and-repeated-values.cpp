class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int repeating,missing;
        int n=grid.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int val=abs(grid[i][j]);
                int row=(val-1)/n;
                int col=(val-1)%n;
                if(grid[row][col]<0){
                    repeating=abs(val);
                    continue;
                }
                grid[row][col]*=(-1);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]>0){
                    missing=(i*n)+(j+1);
                    break;
                }
            }
        }
        return {repeating,missing};
    }
};