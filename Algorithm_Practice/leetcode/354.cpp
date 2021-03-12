#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        if (n == 0)
            return 0;
        sort(envelopes.begin(), envelopes.end(), [](auto& e1, auto& e2) {
            return e1[0] < e2[0] || (e1[0] == e2[0] && e1[1] > e2[1]);
        });
        vector<int> f(n, 1);
        for (int i = 1; i < n; i++)
            for (int j = 0; j < i; j++) {
                if (envelopes[j][1] < envelopes[i][1])
                    f[i] = max(f[i], f[j] + 1);
            }
        return *max_element(f.begin(), f.end());
    }
};