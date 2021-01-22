#include <bits/stdc++.h>
using namespace std;

int n, m, x, y;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int f[1005][1005], ans[100005];
char a[1005][1005];

void dfs(int x, int y, int rev, int idx) {
    if (x < 0 || y < 0 || x >= n || y >= n || f[x][y] != -1 || a[x][y] - '0' != rev)
        return;
    f[x][y] = idx;
    ans[idx]++;
    for (int i = 0; i < 4; i++) {
        int r = x + dir[i][0], c = y + dir[i][1];
        dfs(r, c, !rev, idx);
    }
}

int main() {
    memset(f, -1, sizeof(f));
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        x--;
        y--;
        if (f[x][y] == -1)
            dfs(x, y, a[x][y] - '0', i);
        else ans[i] = ans[f[x][y]];
    }
    for (int i = 1; i <= m; i++)
        cout << ans[i] << "\n";
    return 0;
}