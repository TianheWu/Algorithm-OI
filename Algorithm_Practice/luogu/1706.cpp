#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int n;
vector<int> ans;
unordered_set<int> _set;

void dfs() {
    if (ans.size() == n) {
        for (auto& i:ans)
            cout << setw(5) << i;
        cout << "\n";
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (_set.find(i) != _set.end())
            continue;
        ans.push_back(i);
        _set.insert(i);
        dfs();
        ans.pop_back();
        _set.erase(i);
    }
}

int main() {
    cin >> n;
    dfs();
    return 0;
}