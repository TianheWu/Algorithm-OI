#include <bits/stdc++.h>
using namespace std;

int n, m, u, v;
int vis[100005];
vector<int> edges[100005];

void dfs(int i) {
    if (vis[i] != 0)
        return;
    vis[i] = 1;
    cout << i << " ";
    for (auto v:edges[i]) {
        dfs(v);
    }
}

void bfs() {
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int i = q.front();
        q.pop();
        cout << i << " ";
        vis[i] = 1;
        for (auto v:edges[i]) {
            if (vis[v] == 0) {
                vis[v] = 1;
                q.push(v);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        edges[u].push_back(v);
    }
    for (int i = 1; i <= n; i++)
        sort(edges[i].begin(), edges[i].end());
    dfs(1);
    memset(vis, 0, sizeof(vis));
    cout << "\n";
    bfs();
    return 0;
}