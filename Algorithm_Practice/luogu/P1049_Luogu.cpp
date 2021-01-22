#include <bits/stdc++.h>
using namespace std;

int V, n;
int v[20005], dp[35][20005];

int main() {
    cin >> V >> n;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= V; j++) {
            if (j >= v[i]) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i]] + v[i]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
            
        }
    }
    cout << V - dp[n][V];
    return 0;
}