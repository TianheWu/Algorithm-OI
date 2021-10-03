class Solution {
public:
    int climbStairs(int n) {
        vector<vector<long long>> init_matrix = {{1, 1}, {1, 0}};
        vector<vector<long long>> ret = matrix_quick_pow(init_matrix, n - 1);
        return ret[0][0] + ret[0][1];
    }

    vector<vector<long long>> matrix_quick_pow(vector<vector<long long>> &matrix, int n) {
        vector<vector<long long>> ret = {{1, 0}, {0, 1}};
        while (n > 0) {
            if (n & 1) ret = matrix_mul(ret, matrix);
            matrix = matrix_mul(matrix, matrix);
            n >>= 1;
        }
        return ret;
    }

    vector<vector<long long>> matrix_mul(vector<vector<long long>> &m1, vector<vector<long long>> &m2) {
        vector<vector<long long>> ret = {{0, 0}, {0, 0}};
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                ret[i][j] = m1[i][0] * m2[0][j] + m1[i][1] * m2[1][j];
        return ret;
    }
};