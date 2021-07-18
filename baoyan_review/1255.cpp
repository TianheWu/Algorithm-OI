#include <iostream>
using namespace std;

int N;
long long dp[5005];

int main() {
    cin >> N;
    dp[0] = 1, dp[1] = 1;
    for (int i = 2; i <= N; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[N];
    return 0;
}