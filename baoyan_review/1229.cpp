#include <bits/stdc++.h>
using namespace std;

string pre_order, post_order;
int ans = 1;

int main() {
    cin >> pre_order >> post_order;
    int n = pre_order.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 1; j < n; j++) {
            if (post_order[j] == pre_order[i] && post_order[j - 1] == pre_order[i + 1])
                ans *= 2;
        }
    }
    cout << ans;
    return 0;
}