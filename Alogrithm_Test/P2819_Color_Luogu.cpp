#include <bits/stdc++.h>
using namespace std;

int n, k, m, ans;
int f[105][105], color[105];

bool check(int s) {
    for (int i = 1; i <= s; i++) {
        if (f[i][s] == 1 && color[i] == color[s])
            return false;
    }
    return true;
}

void dfs(int s) {
    if (s > n) {
        ans++;
        return;
    }
    for (int i = 1; i <= m; i++) {
        color[s] = i;
        if (check(s)) {
            dfs(s + 1);
        } else {
            color[s] = 0;
        }
    }
}

int main () {
    cin >> n >> k >> m;
    for (int i = 0; i < k; i++) {
        int u, v;
        cin >> u >> v;
        f[u][v] = 1;
        f[v][u] = 1;
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}