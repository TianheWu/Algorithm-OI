#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N, K;
ll a[100005];

bool check(ll x) {
    ll num = 0;
    for (int i = 0; i < N; i++)
        num += a[i] / x;
    return num >= K;
}

int main() {
    cin >> N >> K;
    ll max_v = 0;
    for (ll i = 0; i < N; i++) {
        cin >> a[i];
        max_v = max(max_v, a[i]);
    }
    ll l = 0, r = max_v;
    while (l < r) {
        ll mid = (l + r + 1) / 2;
        if (check(mid))
            l = mid;
        else r = mid - 1;
    }
    cout << l;
    return 0;
}