#include <bits/stdc++.h>
using namespace std;

int n;
string s;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        int tmp = s.size();
        s[tmp - 1] = '0', s[tmp - 2] = '0', s[tmp - 3] = '0';
        cout << s << "\n";
    }
    return 0;
}