#include <bits/stdc++.h>
using namespace std;

int n, q, a[1000005], l[1000005], r[1000005];
int dp[1000005][1000005];

int main() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[j] == a[i])
                dp[a[i]][j]++;
        }
    }
    for (int i = 1; i <= q; i++) {
        int ans = 0;
        scanf("%d%d", &l[i], &r[i]);
        for (int j = 1; j <= n; j++) {
            if (a[j] == dp[a[j]][r[i]] - dp[a[j]][l[i]])
                ans++;
        }
        cout << ans << "\n";
        
    }
    return 0;
}