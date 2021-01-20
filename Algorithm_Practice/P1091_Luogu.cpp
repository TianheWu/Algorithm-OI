#include <bits/stdc++.h>
using namespace std;

int n, a[105], dp_1[105], dp_2[105];
int max_v = 0;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++) {
        dp_1[i] = 1;
        for (int j = 1; j <= n; j++)
            if (a[j] < a[i])
                dp_1[i] = max(dp_1[i], dp_1[j] + 1);
    }
    for (int i = n; i >= 1; i--) {
        dp_2[i] = 1;
        for (int j = n; j >= 1; j--)
            if (a[j] < a[i])
                dp_2[i] = max(dp_2[i], dp_2[j] + 1);
    }
    for (int i = 1; i <= n; i++)
        max_v = max(dp_1[i] + dp_2[i] - 1, max_v);
    cout << n - max_v;
    return 0;
}