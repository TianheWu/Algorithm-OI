#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[1000005], x;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++) {
        cin >> x;
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (a[mid] < x)
                l = mid + 1;
            else if (a[mid] >= x)
                r = mid;
            if (l == r) {
                if (a[l] == x)
                    cout << l + 1 << " ";
                else cout << -1 << " ";
                break;
            }
        }
    }
    return 0;
}