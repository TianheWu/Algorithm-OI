class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size(), ret = 0, diff = 0;
        if (n <= 2) return 0;
        for (int i = 0; i < n - 2; i++) {
            if (nums[i + 2] - nums[i + 1] == nums[i + 1] - nums[i]) ret += ++diff;
            else diff = 0;
        }
        return ret;
    }
};