#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int c = 1, cur_max = nums[0];
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i + 1] < nums[i]) {
                c--;
                if (i - 1 >= 0 && nums[i + 1] < nums[i - 1])
                    nums[i + 1] = nums[i];
            }
            if (c < 0)
                return false;
        }
        return true;
    }
};