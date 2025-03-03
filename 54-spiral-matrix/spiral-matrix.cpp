class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size();
        int n = matrix[0].size();
        int total_elements = m * n;

        int startingRow = 0;
        int endingCol = n - 1;
        int endingRow = m - 1;
        int startingCol = 0;
        int count = 0;

        while (count < total_elements) {
            // starting row
            for (int i = startingCol; i <= endingCol && count < total_elements; i++) {
                res.push_back(matrix[startingRow][i]);
                count++;
            }
            startingRow++;
            // ending column
            for (int i = startingRow; i <= endingRow && count < total_elements; i++) {
                res.push_back(matrix[i][endingCol]);
                count++;
            }
            endingCol--;
            // ending row
            for (int i = endingCol; i >= startingCol && count < total_elements; i--) {
                res.push_back(matrix[endingRow][i]);
                count++;
            }
            endingRow--;
            // starting column
            for (int i = endingRow; i >= startingRow && count < total_elements; i--) {
                res.push_back(matrix[i][startingCol]);
                count++;
            }
            startingCol++;
        }
        return res;
    }
};
