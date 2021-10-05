class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), max_right = nums[0], step = 0, cur_end = 0;
        for (int i = 0; i < n - 1; i++) {
            max_right = max(max_right, i + nums[i]);
            if (i == cur_end) {
                cur_end = max_right;
                step++;
            }
        }
        return step;
    }
};