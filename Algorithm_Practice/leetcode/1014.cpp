class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int pre_max = values[0] + 0, n = values.size(), ret = values[0] + 0 + values[1] - 1;
        for (int j = 1; j < n; j++) {
            ret = max(ret, pre_max + values[j] - j);
            pre_max = max(pre_max, values[j] + j);
        }
        return ret;
    }
};