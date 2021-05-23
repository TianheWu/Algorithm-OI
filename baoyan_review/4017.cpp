#include <bits/stdc++.h>
using namespace std;

const int MOD = 80112002;

int n, m, u, v, ans;
int indegree[5005], outdegree[5005], vis[5005], d[5005];
vector<int> edges[5005];

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        indegree[v]++;
        outdegree[u]++;
        edges[u].emplace_back(v);
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            vis[i] = 1;
            q.push(i);
            d[i] = 1;
        }
    }
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (auto& i:edges[x]) {
            d[i] = (d[i] + d[x]) % MOD;
            indegree[i]--;
            if (!indegree[i]) {
                if (!outdegree[i]) {
                    ans = (ans + d[i]) % MOD;
                }
                q.push(i);
            }
        }
    }
    cout << ans;
    return 0;
}