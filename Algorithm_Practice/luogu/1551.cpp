#include <bits/stdc++.h>
using namespace std;

int n, m, p, x1, x2, flag;
vector<int> edges[5005];
int vis[5005];

void dfs(int s) {
    if (s == x2) {
        flag = 1;
        return;
    }
    vis[s] = 1;
    for (auto& i:edges[s]) {
        if (!vis[i] && !flag)
            dfs(i);
    }
}

int main() {
    cin >> n >> m >> p;
    for (int i = 0; i < m; i++) {
        cin >> x1 >> x2;
        edges[x1].push_back(x2);
        edges[x2].push_back(x1);
    }
    for (int i = 0; i < p; i++) {
        cin >> x1 >> x2;
        flag = 0;
        memset(vis, 0, sizeof(vis));
        dfs(x1);
        if (flag)
            cout << "Yes";
        else cout << "No";
        cout << "\n";
    }
    return 0;
}