class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //brute forceO(m*n) linear search algortihm

        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==target) return true;
            }
        }
        return false;
    }
};