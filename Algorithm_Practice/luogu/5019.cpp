#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n;
ll a[100005], ans;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++)
        if (a[i] > a[i - 1])
            ans += a[i] - a[i - 1];
    cout << ans + a[0];
    return 0;
}