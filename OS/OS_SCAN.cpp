#include <bits/stdc++.h>
using namespace std;

int a[15], vis[15];
int n, ans, start;
bool flag = false;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int tmp = a[0];
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        if (flag) {
            ans += abs(a[i] - a[i - 1]);
            cout << a[i] << " ";
        }
        if (a[i] == tmp) {
            flag = true;
            start = i;
            cout << a[i] << " ";
        }
    }
    ans += abs(4999 - a[n - 1]);
    cout << 4999 << " ";
    ans += abs(4999 - a[start - 1]);
    cout << a[start - 1] << " ";
    for (int i = start - 1; i > 0; i--) {
        ans += abs(a[i] - a[i - 1]);
        cout << a[i - 1] << " ";
    }
    cout << "\nans = " << ans;
    return 0;
}