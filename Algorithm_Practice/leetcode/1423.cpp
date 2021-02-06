#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int l = n - k, r = 0, max_val = -1, cur_val = 0;
        for (int i = l; i < n; i++)
            cur_val += cardPoints[i];
        max_val = max(max_val, cur_val);
        while (r < k) {
            cur_val = cur_val - cardPoints[l++] + cardPoints[r++];
            max_val = max(max_val, cur_val);
        }
        return max_val;
    }
};