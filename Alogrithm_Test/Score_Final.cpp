#include <bits/stdc++.h>
using namespace std;

double s[20], v[20], ans;
int n;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> s[i] >> v[i];
    double tmp_sum = 0, v_sum = 0;
    for (int i = 1; i <= n; i++) {
        tmp_sum += s[i] * v[i];
        v_sum += v[i];
    }
    ans = tmp_sum * 1.0 / v_sum;
    cout << ans << endl;
    return 0;
}