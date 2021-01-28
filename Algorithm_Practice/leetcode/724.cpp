#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0, cur = 0;
        for (int i = 0; i < nums.size(); i++)
            sum += nums[i];
        for (int i = 0; i < nums.size(); i++) {
            cur += nums[i];
            if (sum - cur == cur - nums[i])
                return i;
        }
        return -1;
    }
};