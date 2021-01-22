#include <bits/stdc++.h>
using namespace std;

int monotoneIncreasingDigits(int N) {
    vector<int> nums;
    int tmp = N, n, ans = 0;
    bool flag = true, flag_0 = true;
    while (tmp > 0) {
        nums.push_back(tmp % 10);
        tmp /= 10;
    }
    reverse(nums.begin(), nums.end());
    n = nums.size();
    for (int i = 1; i < n; i++) {
        if (nums[i] < nums[i - 1]) {
            for (int j = i; j < n; j++)
                nums[j] = 9;
            int p = i - 1;
            while (p - 1 >= 0 && nums[p] == nums[p - 1]) {
                p--;
                flag_0 = false;
            }
            if (!flag_0) {
                for (int j = p + 1; j < n; j++)
                    nums[j] = 9;
                nums[p]--;
            } else {
                nums[i - 1]--;
            }
            break;
        }
    }
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 0 && flag)
            continue;
        ans += nums[i];
        flag = false;
        if (i != nums.size() - 1)
            ans *= 10;
    }
    return ans;
}

int main() {
    int tmp;
    cin >> tmp;
    cout << monotoneIncreasingDigits(tmp);
    return 0;

}