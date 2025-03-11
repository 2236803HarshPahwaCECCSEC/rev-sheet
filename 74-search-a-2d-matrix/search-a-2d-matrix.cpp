class Solution {
public:
// bool binarySearch(vector<int>&nums,int target){
//     int low=0;
//     int high=nums.size()-1;
//     while(low<=high){
//         int mid=low+(high-low)/2;
//         if(nums[mid]==target) return true;
//         else if(nums[mid]<target) low=mid+1;
//         else high=mid-1;
//     }
//     return false;
// }
        // for(int i=0;i<m;i++){
        //     if(matrix[i][0]<=target&&target<=matrix[i][n-1]){
        //         return binarySearch(matrix[i],target);
        //     }
        // }
        // return false;
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //brute forceO(m*n) linear search algortihm

        // int m=matrix.size();
        // int n=matrix[0].size();
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(matrix[i][j]==target) return true;
        //     }
        // }
        // return false;

        //second approach using binary search but with flattening
        int m=matrix.size();
        int n=matrix[0].size();
        int low=0;
        int high=(m*n)-1;        
        while(low<=high){
            int mid=low+(high-low)/2;
            int row=mid/n,col=mid%n;
            if(matrix[row][col]==target) return true;
            else if(matrix[row][col]<target)low=mid+1;
            else high=mid-1;
        }
        return false;
    }
};