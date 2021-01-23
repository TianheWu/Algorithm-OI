#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int n, k, tmp;
unordered_set<int> _set;
vector<int> ans;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        _set.insert(tmp);
    }
    for (auto p = _set.begin(); p != _set.end(); p++) {
        ans.push_back(*p);
    }
    sort(ans.begin(), ans.end());
    if (k - 1 >= ans.size()) {
        cout << "NO RESULT";
        return 0;
    } else cout << ans[k - 1];
    return 0;
}