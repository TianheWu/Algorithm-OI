#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int> ans;
        int n = A.size();
        for (int i = n - 1; i >= 0 || K > 0; i--, K /= 10) {
            if (i >= 0)
                K += A[i];
            ans.push_back(K % 10);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};