#include <bits/stdc++.h>
using namespace std;

int n;
char a[35][35];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dfs(int i, int j) {
    if (i < 0 || j < 0 || i >= n || j >= n || a[i][j] == '1' || a[i][j] == '3')
        return;
    if (a[i][j] == '0') {
        a[i][j] = '3';
    }
    for (int z = 0; z < 4; z++) {
        int r = i + dir[z][0], c = j + dir[z][1];
        dfs(r, c);
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i == 0 || j == 0 || i == n - 1 || j == n - 1) && a[i][j] == '0') {
                dfs(i, j);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == '3')
                a[i][j] = '0';
            else if (a[i][j] == '0')
                a[i][j] = '2';
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}