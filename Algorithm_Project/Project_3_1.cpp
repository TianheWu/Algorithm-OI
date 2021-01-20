#include <bits/stdc++.h>
using namespace std;

/*  Problem: Batch job scheduling problem

    There are n villages in a township (1<n≤20), and there is a salesperson who wants to go to various villages to sell goods.
    The distance s (0 < s < 1000) between the villages is known, and the village A to The roads from Village B 
    to Village A are mostly different. In order to improve efficiency, he starts from the store once to each village, 
    and then returns to the village where the store is located. Assuming that the village where the store is located is 1, 
    he doesn't know what route to choose to make the shortest distance. Please help him choose the shortest way.

*/


int N;
int dp[1 << 20][20], w[20][20], path[1 << 20][20];

void traceback(int u, int i, int s) {
    if (i == 0 && s > 0) {
        cout << i + 1 << " ";
        return;
    }
    int tmp = i;
    int pre_u = u;
    if (s) u ^= (1 << tmp);
    traceback(u, path[pre_u][i], s + 1);
    if (s != 0)
        cout << i + 1 << " ";
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> w[i][j];
    memset(dp, 0x3f, sizeof(dp));
    dp[1][0] = 0;
    for (int i = 1; i < 1 << N; i += 2) {  // 第一个村庄永远是访问过的状态，因此加2即可
        for (int j = 0; j < N; j++) {
            if (!((1 << j) & i)) {   // 该点是否访问过
                for (int k = 0; k < N; k++) {
                    if ((1 << k) & i) {
                        if (dp[i | (1 << j)][j] > dp[i][k] + w[k][j]) { // 将状态i的第j位设置为1，更新最短路
                            dp[i | (1 << j)][j] = dp[i][k] + w[k][j];
                            path[i | (1 << j)][j] = k;
                        }
                    }
                }
            }
        }
    }
    int min_val = INT_MAX;
    for (int i = 0; i < N; i++) {
        if (min_val > dp[(1 << N) - 1][i] + w[i][0]) {
            min_val = dp[(1 << N) - 1][i] + w[i][0];
            path[(1 << N) - 1][0] = i;
        }
    }
    cout << "The min distant = "<< min_val << "\n";
    traceback((1 << N) - 1, 0, 0);
    return 0;
}