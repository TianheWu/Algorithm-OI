class Solution {
public:
    int range_ans(vector<int>& nums, int start, int end) {
        int pre_2 = 0, pre_1, ret;
        if (start == 3) pre_1 = nums[1];
        else pre_1 = nums[0];
        ret = pre_1;
        for (int i = start; i <= end; i++) {
            ret = max(pre_2 + nums[i - 1], pre_1);
            pre_2 = pre_1, pre_1 = ret;
        }
        return ret;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        return max(range_ans(nums, 2, n - 1), range_ans(nums, 3, n));
    }
};