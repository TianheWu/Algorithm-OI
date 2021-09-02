#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int N, ans;
int a[10005];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> a[i];
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}