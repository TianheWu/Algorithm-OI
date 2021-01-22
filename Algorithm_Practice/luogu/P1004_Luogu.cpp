#include <bits/stdc++.h>
using namespace std;

int N, x, y, v;
int grid[12][12], f[12][12][12][12];

int main() {
    cin >> N;
    cin >> x >> y >> v;
    while (x != 0 && y != 0 && v != 0) {
        grid[x][y] = v;
        cin >> x >> y >> v;
    }
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            for (int z = 1; z <= N; z++)
                for (int k = 1; k <= N; k++) {
                    f[i][j][z][k] = max(max(f[i - 1][j][z - 1][k], f[i - 1][j][z][k - 1]), max(f[i][j - 1][z - 1][k], f[i][j - 1][z][k - 1]))
                        + grid[i][j] + grid[z][k];
                    if (i == z && j == k)
                        f[i][j][z][k] -= grid[i][j];
                }
    cout << f[N][N][N][N];
    return 0;
}