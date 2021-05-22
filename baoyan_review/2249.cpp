#include <bits/stdc++.h>
using namespace std;

int n, m, temp;
int a[1000005];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++) {
        cin >> temp;
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (a[mid] >= temp)
                r = mid;
            else if (a[mid] < temp)
                l = mid + 1;
        }
        if (a[l] == temp)
            cout << l + 1 << " ";
        else cout << -1 << " ";
    }
    return 0;
}