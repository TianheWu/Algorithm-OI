class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), ret = nums[0];
        if (n == 1) return true;
        for (int i = 1; i < n; i++)
            if (ret >= i) {
                ret = max(ret, i + nums[i]);
                if (ret >= n - 1) return true;
            }
        return false;
    }
};