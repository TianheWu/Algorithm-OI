class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_val = 0, n = prices.size(), pre = prices[0];
        for (int i = 1; i < n; i++) {
            pre = min(pre, prices[i]);
            max_val = max(max_val, prices[i] - pre);
        }
        return max_val;
    }
};