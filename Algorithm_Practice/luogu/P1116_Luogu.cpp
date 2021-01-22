#include <bits/stdc++.h>
using namespace std;

int N, sum, a[10005];

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> a[i];
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j < i; j++) {
            if (a[j] > a[i]) sum++;
        }
    }
    cout << sum;
    return 0;
}