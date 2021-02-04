#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans = -999999, cur = 0;
        int head = nums[0], pos = 0, count = 0;
        for (int i = 0; i < nums.size(); i++) {
            cur += nums[i];
            count++;
            if (count == k) {
                ans = max(ans, cur / k);
                cur -= head;
                if (++pos < nums.size())
                    head = nums[pos];
                count--;
            }
        }
        return ans;
    }
};