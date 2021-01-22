#include <bits/stdc++.h>
using namespace std;

int n, tmp, max_val = -1;
unordered_map<int, int> _map;
vector<pair<int, int>> ans;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        _map[tmp]++;
    }
    for (auto p = _map.begin(); p != _map.end(); p++) {
        ans.push_back(make_pair(p->first, p->second));
    }
    sort(ans.begin(), ans.end(), [=](pair<int, int> &a, pair<int, int> &b) -> bool {
        return a.first < b.first;
    });
    for (auto p = ans.begin(); p != ans.end(); p++) {
        cout << p->first << " " << p->second << "\n";
    }
    return 0;
}