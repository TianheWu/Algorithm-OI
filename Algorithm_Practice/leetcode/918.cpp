class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int pre_max = nums[0], pre_min = nums[0], sum = nums[0], ret = INT_MIN, n = nums.size();
        int max_val = nums[0], min_val = nums[0];
        for (int i = 1; i < n; i++) {
            pre_max = max(nums[i], pre_max + nums[i]);
            max_val = max(max_val, pre_max);
            pre_min = min(nums[i], pre_min + nums[i]);
            min_val = min(min_val, pre_min);
            sum += nums[i];
        }
        return max(max_val, sum - min_val == 0 ? max_val : sum - min_val);
    }
};