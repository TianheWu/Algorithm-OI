#include<bits/stdc++.h>
using namespace std;

const int MOD = 1000007;

int n, m, a[105];
long long dp[105][105];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) { // 几种花
        for (int j = 0; j <= m; j++) {  // 几盆
            for (int k = 0; k <= min(a[i], j); k++) { // 选择盆数和花允许放的数量的较小值
                dp[i][j] += dp[i - 1][j - k];
                dp[i][j] %= MOD;
            }
        }
    }
    cout << dp[n][m];
    return 0;
}