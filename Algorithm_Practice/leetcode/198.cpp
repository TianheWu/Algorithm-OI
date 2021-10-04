class Solution {
public:
    int rob(vector<int>& nums) {
        int pre_2 = 0, pre_1 = nums[0], n = nums.size(), ret = pre_1;
        for (int i = 2; i <= n; i++) {
            ret = max(pre_2 + nums[i - 1], pre_1);
            pre_2 = pre_1, pre_1 = ret;
        }
        return ret;
    }
};