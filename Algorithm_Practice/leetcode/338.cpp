#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans(num + 1);
        int high_light = 0;
        for (int i = 1; i <= num; i++) {
            if ((i & (i - 1)) == 0)
                high_light = i;
            ans[i] = ans[i - high_light] + 1;
        }
        return ans;
    }
};