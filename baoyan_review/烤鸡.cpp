#include <iostream>
#include <vector>
#include <numeric>
#include <string.h>
#include <algorithm>
using namespace std;

int n;
vector<string> ans;

void search(int current_sum, vector<int> num_vec, int k) {
    if (k == 10) {
        int vec_sum = accumulate(num_vec.begin(), num_vec.end(), 0);
        string s;
        if (vec_sum == n) {
            for (int i = 0; i < num_vec.size(); i++) {
                s += to_string(num_vec[i]);
            }
            ans.push_back(s);
        }
        return;
    }
    for (int i = 1; i <= 3; i++) {
        num_vec.push_back(i);
        search(current_sum + i, num_vec, k + 1);
        num_vec.pop_back();
    }
}

int main() {
    cin >> n;
    if (n < 10 || n > 30) {
        cout << 0;
        return 0;
    }
    vector<int> num_vec;
    search(0, num_vec, 0);
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (auto& s:ans) {
        for (int i = 0; i < s.size(); i++) cout << s[i] << " ";
        cout << "\n";
    }
    return 0;
}