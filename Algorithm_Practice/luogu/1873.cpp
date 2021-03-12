#include <bits/stdc++.h>
using namespace std;

long long N, M, max_v;
long long a[1000005];

bool check(long long mid) {
    long long res = 0;
    for (long long i = 0; i < N; i++) {
        if (a[i] > mid)
            res += a[i] - mid;
    }
    return res >= M;
}

int main() {
    cin >> N >> M;
    for (long long i = 0; i < N; i++) {
        cin >> a[i];
        max_v = max(max_v, a[i]);
    }
    long long l = 0, r = max_v - 1;
    while (l < r) {
        long long mid = (l + r + 1) / 2;
        if (check(mid))
            l = mid;
        else r = mid - 1;
    }
    cout << l;
    return 0;
}