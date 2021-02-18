#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int n = A.size(), ans = 0;
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (!q.empty() && q.front() + K <= i)
                q.pop();
            if (q.size() % 2 == A[i]) {
                if (i + K > n)
                    return -1;
                q.push(i);
                ans++;
            }
        }
        return ans;
    }
};