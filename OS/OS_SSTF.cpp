#include <bits/stdc++.h>
using namespace std;

int a[15], vis[15];
int n, ans;
unordered_map<int, int> _map;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        _map[a[i]] = i;
    vector<int> vec;
    vec.push_back(a[0]);
    vis[0] = 1;
    for (int i = 0; i < n; i++) {
        int v = vec.back();
        int min_diff = 1000007, min_v = -1;
        for (int j = 0; j < n; j++) {
            if (a[j] != v && (!vis[j])) {
                if (min_diff > abs(v - a[j])) {
                    min_diff = abs(v - a[j]);
                    min_v = a[j];
                }
            }
        }
        vis[_map[min_v]] = 1;
        if (min_v != -1)
            vec.push_back(min_v);
    }
    cout << "Seq is: \n";
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << "\n";
    for (int i = 1; i < vec.size(); i++) {
        ans += abs(vec[i] - vec[i - 1]);
    }
    cout << "ans = " << ans;
    return 0;
}