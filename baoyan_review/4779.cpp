#include <bits/stdc++.h>
using namespace std;


int n, m, s, u, v, w;
vector<pair<int, int>> edges[100005];
int dis[100005], vis[100005];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

int main() {
    memset(dis, 0x3f, sizeof(dis));
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        edges[u].push_back(make_pair(w, v));
    }
    dis[s] = 0;
    q.push(make_pair(0, s));
    while (!q.empty()) {
        int now_u = q.top().second;
        q.pop();
        vis[now_u] = 1;
        for (auto& vec:edges[now_u]) {
            int now_v = vec.second, now_w = vec.first;
            if (dis[now_v] > dis[now_u] + now_w) {
                dis[now_v] = dis[now_u] + now_w;
                if (!vis[now_v])
                    q.push(make_pair(dis[now_v], now_v));
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << dis[i] << " ";
    return 0;
}