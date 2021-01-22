#include <bits/stdc++.h>
using namespace std;

int n, m, u, v, w;
int d[1505];
vector<pair<int, int>> graph[1505];
queue<int> q;

void bfs() {
    d[1] = 0;
    q.push(1);
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        for (auto vec:graph[t]) {
            if (d[vec.first] < d[t] + vec.second) {
                d[vec.first] = d[t] + vec.second;
                q.push(vec.first);
            }
        }
    }
}

int main() {
    memset(d, -1, sizeof(d));
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        graph[u].emplace_back(make_pair(v, w));
    }
    bfs();
    cout << d[n];
    return 0;
}