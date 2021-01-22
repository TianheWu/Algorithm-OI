#include <bits/stdc++.h>
using namespace std;

int n, cnt;
struct Node {
    int l, w;
} f[5005];

bool vis[5005];

int main() {
    memset(vis, 0, sizeof(vis));
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> f[i].l >> f[i].w;
    sort(f + 1, f + n + 1, [=](Node a, Node b) -> bool { 
        if (a.l != b.l) return a.l > b.l;
        else return a.w > b.w;
    });
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        cnt++;
        int tmp_w = f[i].w;
        for (int j = i + 1; j <= n ; j++) {
            if (vis[j]) continue;
            if (tmp_w >= f[j].w) {
                tmp_w = f[j].w;
                vis[j] = true;
            }
        }
    }
    cout << cnt;
    return 0;
}