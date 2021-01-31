#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= 0)
                nums[i] = nums.size() + 1;
        }
        for (auto i:nums) {
            int num = abs(i);
            if (num <= nums.size())
                nums[num - 1] = -abs(nums[num - 1]);
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0)
                return i + 1;
        }
        return nums.size() + 1;
    }
};