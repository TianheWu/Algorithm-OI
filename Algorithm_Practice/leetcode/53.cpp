class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), max_val = nums[0];
        int pre = nums[0];
        for (int i = 1; i < n; i++) {
            pre = max(nums[i], pre + nums[i]);
            max_val = max(pre, max_val);
        }
        return max_val;
    }
};