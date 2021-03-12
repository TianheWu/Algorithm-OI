#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, x, ans;
ll a[100005];

int main() {
    cin >> n >> x;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++) {
        if (a[i] > x && i == 0) {
            ans += a[i] - x;
            a[i] -= a[i] - x;
        }
        else if (a[i] + a[i - 1] > x) {
            ans += a[i] + a[i - 1] - x;
            a[i] -= a[i] + a[i - 1] - x;
        }
    }
    cout << ans;
    return 0;
}