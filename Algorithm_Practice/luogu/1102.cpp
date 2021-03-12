#include <bits/stdc++.h>
using namespace std;

long long N, C, ans;
long long a[200005];
unordered_map<long long, long long> _map;

int main() {
    cin >> N >> C;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        _map[a[i]]++;
    }
    for (int i = 0; i < N; i++) {
        if (_map.find(a[i] - C) != _map.end())
            ans += _map[a[i] - C];
    }
    cout << ans;
    return 0;
}