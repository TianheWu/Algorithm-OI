#include <bits/stdc++.h>
using namespace std;

long long L, N, M;
long long D[50005];

bool check(int x) {
    int num = 0, now = 0;
    for (int i = 1; i <= N + 1; i++) {
        if (D[i] - D[now] < x)
            num++;
        else {
            now = i;
        }
    }
    return num > M ? false : true; 
}

int main() {
    cin >> L >> N >> M;
    for (long long i = 1; i <= N; i++)
        cin >> D[i];
    D[N + 1] = L;
    long long l = 0, r = L;
    while (l < r) {
        int mid = (l + r + 1) / 2;
        if (check(mid))
            l = mid;
        else r = mid - 1;
    }
    cout << l;
    return 0;
}