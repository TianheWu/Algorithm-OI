class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size(), pre_0 = 0, pre_1 = -prices[0];
        for (int i = 1; i < n; i++) {
            pre_0 = max(pre_0, pre_1 + prices[i] - fee);
            pre_1 = max(pre_1, pre_0 - prices[i]);
        }
        return pre_0;
    }
};