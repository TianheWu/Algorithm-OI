#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int N, M, u, v;
vector<int> edges[100005];
int max_idx[100005];

void dfs(int s, int cur_max_idx) {
    max_idx[s] = cur_max_idx;
    for (auto& i:edges[s]) {
        if (!max_idx[i]) dfs(i, cur_max_idx);
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> u >> v;
        edges[v].push_back(u);
    }
    for (int i = N; i >= 1; i--) {
        if (!max_idx[i]) dfs(i, i);
    }
    for (int i = 1; i <= N; i++) cout << max_idx[i] << " ";
    return 0;
}