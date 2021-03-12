#include <bits/stdc++.h>
using namespace std;

int n, x, ans;
priority_queue<int, vector<int>, greater<int>> q; 

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        q.push(x);
    }
    while (q.size() != 1) {
        int v1 = q.top();
        q.pop();
        int v2 = q.top();
        q.pop();
        ans += v1 + v2;
        q.push(v1 + v2);
    }
    cout << ans;
    return 0;
}