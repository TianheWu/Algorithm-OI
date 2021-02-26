#include <bits/stdc++.h>
using namespace std;

int f(vector<int>& nums) {
    int t = 0, n = nums.size() + 1;
    for (int i = 1; i <= n; i++)
        t ^= i;
    for (int i = 0; i < n - 1; i++)
        t ^= nums[i];
    return t;
}