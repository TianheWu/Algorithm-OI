#include <iostream>
using namespace std;

int n, m, x_h, y_h;
int grid[25][25];
long long dp[25][25];

int dir[8][2] = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}};

int main() {
    cin >> n >> m >> x_h >> y_h;
    grid[x_h][y_h] = 1;
    for (int i = 0; i < 8; i++) {
        int x = x_h + dir[i][0], y = y_h + dir[i][1];
        if (x >= 0 && x <= n && y >= 0 && y <= m) grid[x][y] = 1;
    }
    for (int i = 0; i <= n; i++) {
        if (!grid[i][0])
            dp[i][0] = 1;
        else break;
    }
    for (int i = 0; i <= m; i++) {
        if (!grid[0][i])
            dp[0][i] = 1;
        else break;
    }
    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= m; j++) {
    //         cout << grid[i][j];
    //     }
    //     cout << "\n";
    // }
    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= m; j++) {
    //         cout << dp[i][j];
    //     }
    //     cout << "\n";
    // }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (grid[i][j]) dp[i][j] = 0;
            else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    cout << dp[n][m];
    return 0;
}