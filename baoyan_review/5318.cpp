#include <bits/stdc++.h>
using namespace std;

int n, m, u, v;
int vis[100005];
vector<int> edges[100005];

void dfs(int s) {
    cout << s << " ";
    vis[s] = 1;
    for (auto& v:edges[s]) {
        if (!vis[v])
            dfs(v);
    }
}

void bfs(int s) {
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        cout << x << " ";
        for (auto& i:edges[x]) {
            if (!vis[i]) {
                vis[i] = 1;
                q.push(i);
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
    bfs(1);
    return 0;
}