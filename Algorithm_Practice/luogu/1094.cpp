#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll w, n, ans;
ll a[30005];

int main() {
    cin >> w >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    ll l = 0, r = n - 1;
    while (l <= r) {
        if (a[l] + a[r] > w)
            r--;
        else l++, r--;
        ans++;
    }
    cout << ans;
    return 0;
}