#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans, pre;
        pre.resize(1, 0);
        for (int i = 0; i <= rowIndex; i++) {
            ans.resize(i + 1);
            ans[0] = ans[i] = 1;
            for (int j = 1; j < i; j++) {
                ans[j] = pre[j] + pre[j - 1];
            }
            pre = ans;
        }
        return ans;
    }
};