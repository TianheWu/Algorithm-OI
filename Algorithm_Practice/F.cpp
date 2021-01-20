#include <bits/stdc++.h>
using namespace std;

int dp[10005];

int main() {
    dp[0] = 1, dp[1] = 1;
    for (int i = 2; i <= 13; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
        cout << "dp[" << i << "] = " << dp[i] << endl;
    }
    return 0;
}