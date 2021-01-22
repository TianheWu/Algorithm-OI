#include <bits/stdc++.h>
using namespace std;

int N, M;
int vis[100005], max_v[100005];
vector<int> edge[100005];

void dfs(int i, int start) {
    if (max_v[i] != 0)
        return;
    max_v[i] = start;
    for (auto& v:edge[i]) {
        if (!max_v[v]) {
            dfs(v, start);
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        int _u, _v;
        cin >> _u >> _v;
        edge[_v].emplace_back(_u);
    }
    for (int i = N; i >= 1; i--)
        dfs(i, i);
    for (int i = 1; i <= N; i++)
        cout << max_v[i] << " ";
    return 0;
}