#include <iostream>
#include <cstring>
#include <unordered_map>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int n, max_length = 0, ans_i;
string s, pre_max = "";

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        int tmp_size = s.size();
        if (tmp_size > max_length)
        {
            max_length = tmp_size;
            pre_max = s;
            ans_i = i;
        }
        else if (tmp_size == max_length)
        {
            if (s > pre_max)
            {
                pre_max = s;
                ans_i = i;
            }
        }
    }
    cout << ans_i + 1 << "\n";
    cout << pre_max << "\n";
    return 0;
}