#include <bits/stdc++.h>
using namespace std;

int N, M, T, SX, SY, FX, FY, x, y, ans;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int grid[10][10];

void dfs(int _x, int _y) {
    grid[_x][_y] = 2;
    if (_x == FX && _y == FY) {
        ans++;
        return;
    }
    for (int i = 0; i < 4; i++) {
        int r = _x + dir[i][0], c = _y + dir[i][1];
        if (r >= 1 && c >= 1 && r <= N && c <= M && grid[r][c] == 0) {
            dfs(r, c);
            grid[r][c] = 0;
        }
    }
}

int main() {
    cin >> N >> M >> T;
    cin >> SX >> SY >> FX >> FY;
    for (int i = 0; i < T; i++) {
        cin >> x >> y;
        grid[x][y] = 1;
    }
    dfs(SX, SY);
    cout << ans;
    return 0;
}