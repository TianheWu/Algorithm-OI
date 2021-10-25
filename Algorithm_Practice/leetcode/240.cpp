class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size(), x_pos = 0, y_pos = n - 1;
        while (x_pos < m && y_pos >= 0) {
            if (target > matrix[x_pos][y_pos]) x_pos++;
            else if (target < matrix[x_pos][y_pos]) y_pos--;
            else return true;
        }
        return false;
    }
};