#include <bits/stdc++.h>
using namespace std;

int n, m, tmp_p, tmp_q, sum, ans;
struct Node {
    int p, q;
    Node() {}
    Node(int _p, int _q) : p(_p), q(_q) {}
};

Node a[5005];

bool cmp(Node a, Node b) {
    return a.p < b.p;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> tmp_p >> tmp_q;
        a[i].p = tmp_p;
        a[i].q = tmp_q;
    }
    sort(a, a + m, cmp);
    for (int i = 0; i < m && sum <= n; i++) {
        if (sum + a[i].q <= n) {
            sum += a[i].q;
            ans += a[i].p * a[i].q;
        } else {
            ans += a[i].p * (n - sum);
            break;
        }
    }
    cout << ans;
    return 0;
}