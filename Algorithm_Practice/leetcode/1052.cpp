#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int sum = 0, l = 0, ans = 0, cur = 0;
        for (int i = 0; i < customers.size(); i++)
            if (grumpy[i] == 0)
                sum += customers[i];
        int window_val = 0, del_val = 0;
        for (int i = 0; i < X - 1; i++) {
            window_val += customers[i];
            if (grumpy[i] == 0)
                del_val += customers[i];
        }
        for (int i = X - 1; i < customers.size(); i++) {
            window_val += customers[i];
            if (grumpy[i] == 0)
                del_val += customers[i];
            cur = sum - del_val + window_val;
            ans = max(cur, ans);
            if (grumpy[l] == 0)
                del_val -= customers[l];
            window_val -= customers[l];
            l++;
        }
        return ans;
    }
};