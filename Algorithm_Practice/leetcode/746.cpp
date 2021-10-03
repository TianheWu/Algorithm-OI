class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int pre_1 = min(cost[0], cost[1]), pre_2 = 0, ret = pre_1, n = cost.size();
        for (int i = 3; i <= n; i++) {
            ret = min(pre_1 + cost[i - 1], pre_2 + cost[i - 2]);
            pre_2 = pre_1, pre_1 = ret;
        }
        return ret;
    }
};