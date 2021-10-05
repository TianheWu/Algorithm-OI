class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int max_val = *max_element(nums.begin(), nums.end());
        int arr[max_val + 5];
        memset(arr, 0, sizeof(arr));
        for (int i = 0; i < nums.size(); i++) arr[nums[i]]++;
        int pre_2 = 0, pre_1 = max(arr[0] * 0, arr[1] * 1), ret = pre_1;
        for (int i = 2; i <= max_val; i++) {
            ret = max(pre_2 + arr[i] * i, pre_1);
            pre_2 = pre_1;
            pre_1 = ret;
        }
        return ret;
    }
};