#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int ans = 0, start = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] <= nums[i - 1])
                start = i;
            ans = max(ans, i - start + 1);
        }
        return ans;
    }
};