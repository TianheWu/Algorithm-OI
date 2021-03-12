#include <bits/stdc++.h>
using namespace std;

int N, M, ans = INT_MAX;
char grid[55][55];

int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            cin >> grid[i][j];
    for (int i = 1; i <= N - 2; i++) {
        for (int j = i + 1; j <= N - 1; j++) {
            int tmp = 0;
            for (int k = 1; k <= i; k++)
                for (int g = 1; g <= M; g++)
                    if (grid[k][g] != 'W')
                        tmp++;
            for (int k = i + 1; k <= j; k++)
                for (int g = 1; g <= M; g++)
                    if (grid[k][g] != 'B')
                        tmp++;
            for (int k = j + 1; k <= N; k++)
                for (int g = 1; g <= M; g++)
                    if (grid[k][g] != 'R')
                        tmp++;
            ans = min(ans, tmp);
        }
    }
    cout << ans;
    return 0;
}