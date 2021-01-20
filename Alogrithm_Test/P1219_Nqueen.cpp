#include <bits/stdc++.h>
using namespace std;

int N, ans;
int a[100], b[100], c[100], d[100];

void dfs(int i) { // i is row
    if (i > N) {
        if (ans <= 2) {
            for (int k = 1; k <= N; k++)
                cout << a[k] << " ";
            cout << "\n";
        }
        ans++;
        return;
    } else {
        for (int j = 1; j <= N; j++) {
            if ((!b[j]) && (!c[i + j]) && (!d[i - j + N])) {
                a[i] = j;
                b[j] = 1;
                c[i + j] = 1;
                d[i - j + N] = 1;
                dfs(i + 1);
                b[j] = 0;
                c[i + j] = 0;
                d[i - j + N] = 0;
            }
        }
    }
}

int main() {
    cin >> N;
    dfs(1);
    cout << ans;
    return 0;
}