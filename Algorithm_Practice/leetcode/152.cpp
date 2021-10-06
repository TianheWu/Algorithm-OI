class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), max_val = nums[0], min_val = nums[0], ret = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] >= 0) {
                max_val = max(nums[i], max_val * nums[i]);
                min_val = min(nums[i], min_val * nums[i]);
            } else {
                int cmp_1 = min_val * nums[i], cmp_2 = max_val * nums[i];
                max_val = max(cmp_1, nums[i]);
                min_val = min(cmp_2, nums[i]);
            }
            ret = max(ret, max_val);
        }
        return ret;
    }
};