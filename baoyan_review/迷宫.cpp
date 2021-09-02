#include <iostream>
using namespace std;

int N, M, T, SX, SY, FX, FY, x, y, ans;
long long grid[10][10], vis[10][10];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void search(int i, int j) {
    vis[i][j] = 1;
    if (i == FX && j == FY) {
        ans++;
        return;
    }
    for (int k = 0; k < 4; k++) {
        int new_i = i + dir[k][0], new_j = j + dir[k][1];
        if (new_i >= 1 && new_i <= N && new_j >= 1 && new_j <= M && (!grid[new_i][new_j]) && (!vis[new_i][new_j])) {
            search(new_i, new_j);
            vis[new_i][new_j] = 0;
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
    search(SX, SY);
    cout << ans;
    return 0;

}