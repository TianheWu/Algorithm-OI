#include <bits/stdc++.h>
using namespace std;

int C, N, vi[105], wi[105], dp[105][10005];

int main () {
    cin >> C >> N;
    for (int i = N; i >= 1; i--) 
        cin >> vi[i] >> wi[i];
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= C; j++) {
            if (j >= wi[i]) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - wi[i]] + vi[i]);
            } else dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[N][C] << "\n";
    int i = N, j = C;
    while (i > 0) {
        if (j >= wi[i] && dp[i][j] == dp[i - 1][j - wi[i]] + vi[i]) {
            cout << N + 1 - i << "\n";
            j -= wi[i];
        }
        i--;
    }
    return 0;
}