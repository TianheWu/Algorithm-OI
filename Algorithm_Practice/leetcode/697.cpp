#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, vector<int>> _map;
        int max_v = 0, ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (_map.count(nums[i])) {
                _map[nums[i]][0]++;
                _map[nums[i]][2] = i;
            } else _map[nums[i]] = {1, i, i};
        }
        for (auto& [_, v]:_map) {
            if (max_v < v[0]) {
                max_v = v[0];
                ans = v[2] - v[1] + 1;
            }
            else if (max_v == v[0]) {
                if (ans > v[2] - v[1] + 1)
                    ans = v[2] - v[1] + 1;
            }   
        }
        return ans;
    }
};