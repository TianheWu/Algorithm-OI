#include<bits/stdc++.h>
using namespace std;

int R, C, grid[105][105], mem[105][105], ans = 0;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int dfs(int i, int j) {
    if (mem[i][j] != 0)
        return mem[i][j];
    mem[i][j]++;
    for (int z = 0; z < 4; z++) {
        int r = i + dir[z][0], c = j + dir[z][1];
        if (r >= 0 && r < R && c >= 0 && c < C && grid[r][c] < grid[i][j])
            mem[i][j] = max(mem[i][j], dfs(r, c) + 1);
    }
    return mem[i][j];
}

int main() {
    cin >> R >> C;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            cin >> grid[i][j];
    
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            ans = max(ans, dfs(i, j));
        }
    }
    cout << ans;
    return 0;
}