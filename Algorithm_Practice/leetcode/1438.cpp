#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> queMax, queMin;
        int l = 0, n = nums.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            while (!queMax.empty() && queMax.back() < nums[i])
                queMax.pop_back();
            while (!queMin.empty() && queMin.back() > nums[i])
                queMin.pop_back();
            queMax.push_back(nums[i]);
            queMin.push_back(nums[i]);
            while (!queMax.empty() && !queMin.empty() && queMax.front() - queMin.front() > limit) {
                if (nums[l] == queMax.front())
                    queMax.pop_front();
                if (nums[l] == queMin.front())
                    queMin.pop_front();
                l++;
            }
            ans = max(ans, i - l + 1);
        }
        return ans;
    }
};