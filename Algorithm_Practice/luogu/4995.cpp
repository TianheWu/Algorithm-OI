#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, ans, flag;
ll a[305];

int main() {
    cin >> n;
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    sort(a, a + n + 1);
    ll l = 0, r = n;
    while (l < r) {
        ans += pow(a[r] - a[l], 2);
        if (!flag) {
            l++;
            flag = 1;
        } else {
            r--;
            flag = 0;
        }
    }
    cout << ans;
    return 0;
}