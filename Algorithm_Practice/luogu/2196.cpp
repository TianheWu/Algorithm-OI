#include <bits/stdc++.h>
using namespace std;

int N, x, ans;
int nums[25], vis[25];
vector<int> edges[25], ans_path;

void dfs(int s, int cur, vector<int> path) {
    if (ans < cur) {
        ans = cur;
        ans_path = path;
    }
    for (auto& v:edges[s]) {
        if (!vis[v]) {
            vis[v] = 1;
            path.push_back(v);
            dfs(v, cur + nums[v], path);
            path.pop_back();
            vis[v] = 0;
        }
    }
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) 
        cin >> nums[i];
    for (int i = 1; i < N; i++) {
        for (int j = i + 1; j <= N; j++) {
            cin >> x;
            if (x)
                edges[i].push_back(j);
        }
    }
    for (int i = 1; i <= N; i++) {
        vector<int> path;
        path.push_back(i);
        memset(vis, 0 , sizeof(vis));
        dfs(i, nums[i], path);
    }
    for (auto& i:ans_path)
        cout << i << " ";
    cout << "\n";
    cout << ans;
    return 0;
}