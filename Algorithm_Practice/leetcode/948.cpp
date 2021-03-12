#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        sort(tokens.begin(), tokens.end());
        int n = tokens.size(), l = 0, r = n - 1, cur_p = P, score = 0;
        while (l <= r) {
            if (cur_p >= tokens[l]) {
                cur_p -= tokens[l++];
                score++;
            } else {
                if (score >= 1 && r - 1 > l) {
                    score--;
                    cur_p += tokens[r--];
                } else break;
            }
        }
        return score;
    }
};