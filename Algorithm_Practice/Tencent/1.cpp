#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[1000005], t[1000005];

int main() {
    fill(a, a + 1000005, 1);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
    }
    for (int i = 1; i <= k; i++) {
        int ans = INT_MAX, ans_i = 0;
        for (int j = 1; j <= n; j++) {
            if (ans > a[j] * t[j]) {
                ans = a[j] * t[j];
                ans_i = j;
            }
        }
        cout << ans_i << "\n";
        a[ans_i]++;
    }
    return 0;
}