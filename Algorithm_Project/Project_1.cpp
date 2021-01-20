#include <bits/stdc++.h>
using namespace std;

/*  Problem: Generalized knapsack problem

    Given a backpack with a load capacity of M and N kinds of items,
    each item has a certain weight and value.

    Now it is necessary to design an algorithm to select items cleverly 
    so that the total number of items loaded into the backpack is not exceeded Maximize value.

*/

int M, N;
int w[10005], v[10005], ans[10005];
int dp[10005][10005], path[10005][10005];

int main() {
    cin >> M >> N;
	for (int i = 1; i <= N; i++)
		cin >> w[i] >> v[i];
	for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (j >= w[i]) {
                if (dp[i - 1][j] < dp[i][j - w[i]] + v[i]) {
                    dp[i][j] = dp[i - 1][j];
                    path[i][j];
                } else dp[i][j] = dp[i - 1][j];
            } else dp[i][j] = dp[i - 1][j];
        }
    }
	
    int i = N, j = M;
    while (i > 0 && j > 0) {
        if (path[i][j]) {
            ans[i]++;
            j -= w[i];
        } else i--;
    }
    for (int i = 1; i <= N; i++)
        cout << "The object " << i << " needs " << ans[i] << endl;

    cout << "The max value is " << dp[M] << endl;
    return 0;
}