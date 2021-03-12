#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll m, n, ans;
ll a[100005], b;

bool flag = false;

int main() {
    cin >> m >> n;
    for (ll i = 0; i < m; i++)
        cin >> a[i];
    sort(a, a + m);
    for (ll i = 0; i < n; i++) {
        cin >> b;
        ll l = 0, r = m - 1, ret = 0;
        while (l < r) {
            ll mid = (l + r + 1) / 2;
            if (a[mid] <= b) {
                l = mid;
            }
            else if (a[mid] > b) {
                r = mid - 1;
            }
        }
        ans += min(abs(b - a[l]), abs(b - a[r + 1]));
    }
    cout << ans;
    return 0;
}