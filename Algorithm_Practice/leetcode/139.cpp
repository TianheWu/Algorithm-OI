class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> sets;
        for (int i = 0; i < wordDict.size(); i++) sets.insert(wordDict[i]);
        int n = s.size();
        bool dp[n + 5];
        memset(dp, false, sizeof(dp));
        dp[0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && (sets.find(s.substr(j, i - j)) != sets.end())) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};