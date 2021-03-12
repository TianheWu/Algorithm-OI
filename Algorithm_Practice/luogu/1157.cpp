#include <bits/stdc++.h>
using namespace std;

int n, r;
vector<int> vec;

void dfs(int start) {
    if (vec.size() == r) {
        for (auto& i:vec)
            cout << setw(3) << i;
        cout << "\n";
        return;
    }
    for (int i = start; i <= n; i++) {
        vec.push_back(i);
        dfs(i + 1);
        vec.pop_back();
    }
}

int main() {
    cin >> n >> r;
    dfs(1);
    return 0;
}