class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int pos_len = 0, neg_len = 0, ret = 0, n = nums.size();
        if (nums[0] > 0) pos_len = 1, ret += 1;
        else if (nums[0] < 0) neg_len = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] > 0) {
                pos_len = max(1, pos_len + 1);
                if (neg_len != 0) neg_len += 1; 
            }
            else if (nums[i] < 0) {
                int cmp_1 = 0, cmp_2 = 0;
                if (pos_len != 0) cmp_1 = pos_len + 1;
                if (neg_len != 0) cmp_2 = neg_len + 1;
                neg_len = max(cmp_1, 1);
                pos_len = max(cmp_2, 0);
            }
            else {
                pos_len = 0, neg_len = 0;
            }
            ret = max(ret, pos_len);
        }
        return ret;
    }
};