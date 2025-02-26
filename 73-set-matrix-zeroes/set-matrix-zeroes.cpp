class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // unordered_set<int>rows; brute force approach using O(m+n)space
        // unordered_set<int>cols;

        // for(int i=0;i<matrix.size();i++){
        //     for(int j=0;j<matrix[0].size();j++){
        //         if(matrix[i][j]==0){
        //             rows.insert(i);
        //             cols.insert(j);
        //         }
        //     }
        // }
        // for(int i=0;i<matrix.size();i++){
        //     for(int j=0;j<matrix[0].size();j++){
        //         if(rows.count(i)>0||cols.count(j)>0){
        //             matrix[i][j]=0;
        //         }
        //     }
        // }

        //using O(1)space 


        int m=matrix.size();
        int n=matrix[0].size();
        bool firstrowzero=false,firstcolzero=false;
        for(int i=0;i<n;i++){
            if(matrix[0][i]==0) firstrowzero=true;
        }
        for(int j=0;j<m;j++){
            if(matrix[j][0]==0) firstcolzero=true;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][0]==0||matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }
        if(firstrowzero){
            for(int i=0;i<n;i++){
                matrix[0][i]=0;
            }
        }
        if(firstcolzero){
            for(int j=0;j<m;j++){
                matrix[j][0]=0;
            }
        }
    }
};