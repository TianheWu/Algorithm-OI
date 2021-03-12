#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        int max_position = max_element(nums.begin(), nums.end()) - nums.begin();
        vector<int> ans(n, -1);
        stack<pair<int, int>> _stack;
        for (int i = 0; i < n; i++) {
            while (!_stack.empty() && nums[i] > _stack.top().first) {
                ans[_stack.top().second] = nums[i];
                _stack.pop();
            }
            _stack.push(make_pair(nums[i], i));
        }
        for (int i = 0; i <= max_position; i++) {
            while (!_stack.empty() && nums[i] > _stack.top().first) {
                ans[_stack.top().second] = nums[i];
                _stack.pop();
            }
        }
        return ans;
    }
};