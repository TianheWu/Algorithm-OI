#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0, l = 0;
        for (int r = 0; r < nums.size(); r++) {
            if (nums[r] != 1)
                l = r + 1;
            ans = max(r - l + 1, ans);
        }
        return ans;
    }
};