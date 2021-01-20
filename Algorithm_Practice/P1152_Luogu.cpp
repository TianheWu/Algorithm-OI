#include <bits/stdc++.h>
using namespace std;

int N, a[1005], d[10005];

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> a[i];
    for (int i = 1; i < N; i++) {
        int tmp = abs(a[i] - a[i + 1]);
        if (tmp >= N) {
            cout << "Not jolly";
            return 0;
        }
        d[tmp]++;
    }
    for (int i = 1; i <= N - 1; i++) {
        if (d[i] == 0) {
            cout << "Not jolly";
            return 0;
        }
    }
    cout << "Jolly";
    return 0;
}