#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int n;
vector<string> a;
string ans;

bool cmp(string cmp_1, string cmp_2) {
    return cmp_1 + cmp_2 >= cmp_2 + cmp_1;
}

int main() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), cmp);
    for (int i = 0; i < n; i++) ans += a[i];
    cout << ans;
    return 0;
}