class Solution {
public:
    int fib(int n) {
        if (n < 2) return n;
        vector<vector<int>> set_matrix = {{1, 1}, {1, 0}};
        vector<vector<int>> ret;
        ret = matrix_pow(set_matrix, n - 1);
        return ret[0][0];
    }

    vector<vector<int>> matrix_pow(vector<vector<int>> &matrix, int n) {
        vector<vector<int>> ret = {{1, 0}, {0, 1}};
        while (n) {
            if (n & 1) ret = matrix_multiply(ret, matrix);
            matrix = matrix_multiply(matrix, matrix);
            n >>= 1;
        }
        return ret;
    }

    vector<vector<int>> matrix_multiply(vector<vector<int>> &m1, vector<vector<int>> &m2) {
        vector<vector<int>> ret = {{0, 0}, {0, 0}};
        for (int i = 0; i < m1.size(); i++)
            for (int j = 0; j < m2.size(); j++)
                ret[i][j] = m1[i][0] * m2[0][j] + m1[i][1] * m2[1][j];
        return ret;
    }
};