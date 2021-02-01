#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sum_A = accumulate(A.begin(), A.end(), 0);
        int sum_B = accumulate(B.begin(), B.end(), 0);
        unordered_set<int> _set(A.begin(), A.end());
        vector<int> ans;
        for (auto i:B) {
            int tmp = (sum_A - sum_B) / 2 + i;
            if (_set.count(tmp)) {
                ans = {tmp, i};
                break;
            }
        }
        return ans;
    }
};