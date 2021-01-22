#include <bits/stdc++.h>
using namespace std;

long long n, x[5005], y[5005], ans = 1e9 + 7;
struct Node {
    long long x, y;
};
Node arr[5005];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                arr[cnt].x = x[j] - x[i];
                arr[cnt].y = y[j] - y[i];
                cnt++;
            }
        }
        sort(arr, arr + cnt, [=](Node a, Node b) -> bool {
            return a.x * b.y - a.y * b.x > 0;
        });
        for (int j = 1; j < cnt; j++) {
            if (ans > abs(arr[j].y * arr[j - 1].x - arr[j].x * arr[j - 1].y))
                ans = abs(arr[j].y * arr[j - 1].x - arr[j].x * arr[j - 1].y);
        }
    }
    printf("%.3f\n", ans / 2.0);
    return 0;
}