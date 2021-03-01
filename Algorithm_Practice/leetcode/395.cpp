#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        int a[26];
        memset(a, 0, sizeof(a));
        for (auto& c:s)
            a[c - 'a']++;
        vector<int> pos;
        int ans = 0, l = 0, n = s.size();
        for (int i = 0; i < n; i++) {
            if (a[s[i] - 'a'] < k)
                pos.push_back(i);
        }
        if (pos.size() <= 0)
            return n;
        for (int i = 0; i < pos.size(); i++) {
            int len = pos[i] - l;
            if (len >= k && len > ans)
                ans = max(ans, longestSubstring(s.substr(l, len), k));
            l = pos[i] + 1;
        }
        if (l < n - 1)
            ans = max(ans, longestSubstring(s.substr(l, n - 1 - l + 1), k));
        return ans;
    }
};