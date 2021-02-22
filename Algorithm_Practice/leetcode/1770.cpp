#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int f[1009][1009];
        int ans = -INT_MAX;
        memset(f, 0, sizeof(f));
        int n = nums.size(), m = multipliers.size();
        for (int i = 1; i <= m; i++)
            f[0][i] = f[0][i - 1] + nums[n - i] * multipliers[i - 1];
        for (int i = 1; i <= m; i++)
            f[i][0] = f[i - 1][0] + nums[i - 1] * multipliers[i - 1];
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j + i <= m; j++)
                f[i][j] = max(f[i - 1][j] + nums[i - 1] * multipliers[i + j - 1], f[i][j - 1] + nums[n - j] * multipliers[i + j - 1]);
        }
        for (int i = 0; i < m; i++)
            ans = max(ans, f[i][m - i]);
        return ans;
    }
};