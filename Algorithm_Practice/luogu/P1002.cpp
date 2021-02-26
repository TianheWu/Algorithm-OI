#include <bits/stdc++.h>
using namespace std;

int b1, b2, h1, h2;
long long f[25][25], dp[25][25];
int dir[8][2] = {{-2, 1}, {-2, -1}, {-1, 2}, {-1, -2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}};

int main() {
    cin >> b1 >> b2 >> h1 >> h2;
    f[h1][h2] = -1;
    for (int i = 0; i < 8; i++) {
        int r = h1 + dir[i][0], c = h2 + dir[i][1];
        if (r >= 0 && c >= 0 && r <= b1 && c <= b2)
            f[r][c] = -1;
    }
    for (int i = 0; i <= b2; i++)
        if (f[0][i] != - 1)
            dp[0][i] = 1;
        else break;
    for (int i = 0; i <= b1; i++)
        if (f[i][0] != - 1)
            dp[i][0] = 1;
        else break;
    for (int i = 1; i <= b1; i++) {
        for (int j = 1; j <= b2; j++) {
            if (f[i][j] != - 1) {
                if (f[i - 1][j] == -1 && f[i][j - 1] != -1)
                    dp[i][j] = dp[i][j - 1];
                else if (f[i - 1][j] != -1 && f[i][j - 1] == -1)
                    dp[i][j] = dp[i - 1][j];
                else if (f[i - 1][j] != -1 && f[i][j - 1] != -1)
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
    cout << dp[b1][b2];
    return 0;
}