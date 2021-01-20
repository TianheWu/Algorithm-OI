#include <bits/stdc++.h>
using namespace std;

int m, n;
int dir[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
char grid[105][105];
int _map[105][105];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '*') {
                for (int z = 0; z < 8; z++) {
                    int r = i + dir[z][0], c = j + dir[z][1];
                    if (r >= 0 && r < n && c >= 0 && c < m && grid[r][c] != '*')
                        _map[r][c]++;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '*')
                cout << '*';
            else cout << _map[i][j];
        }
        cout << "\n";
    }
    return 0;
}