#include <bits/stdc++.h>
using namespace std;

int n, sum, x;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        sum += x / 3;
    }
    cout << sum;
    return 0;
}