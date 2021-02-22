#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i + 1 < m && j + 1 < n)
                    if (matrix[i][j] != matrix[i + 1][j + 1])
                        return false;
            }
        }
        return true;
    }
};