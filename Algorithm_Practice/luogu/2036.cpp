#include <bits/stdc++.h>
using namespace std;

int n, ans = INT_MAX;
int s[15], b[15];

void dfs(int start, int cur_s, int cur_b) {
    for (int i = start; i < n; i++) {
        cur_s *= s[i];
        cur_b += b[i];
        ans = min(ans, abs(cur_s - cur_b));
        dfs(i + 1, cur_s, cur_b);
        cur_s /= s[i];
        cur_b -= b[i];
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> s[i] >> b[i];
    dfs(0, 1, 0);
    cout << ans;
    return 0;
}