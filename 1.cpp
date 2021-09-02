#include <bits/stdc++.h>
using namespace std;

vector<int> edge_up2down[100005];
vector<int> edge_left2right[100005];

int m, n, temp_idx_1, temp_idx_2, temp_rule;
int indegree_up2down[100005];
int indegree_left2right[100005];
int vis[100005];
queue<int> q_up2down;
queue<int> q_left2right;
// A在B上边0，下边1，左边2，右边3

bool check(int rule) {
    if (rule == 1) {
        while (!q_up2down.empty()) {
            int temp_idx = q_up2down.front();
            q_up2down.pop();
            for (auto& i:edge_up2down[temp_idx]) {
                indegree_up2down[i]--;
                if (indegree_up2down[i] == 0 && (!vis[i])) {
                    vis[i] = 1;
                    q_up2down.push(i);
                }
            }
        }
        for (int i = 0; i < m; i++) {
            if (!vis[i]) return false;
        }
    }
    else if (rule == 2) {
        while (!q_left2right.empty()) {
            int temp_idx = q_left2right.front();
            q_left2right.pop();
            for (auto& i:edge_left2right[temp_idx]) {
                indegree_left2right[i]--;
                if (indegree_left2right[i] == 0 && (!vis[i])) {
                    vis[i] = 1;
                    q_left2right.push(i);
                }
            }
        }
        for (int i = 0; i < m; i++) {
            if (!vis[i]) return false;
        }
    }
    return true;
}

int main() {
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp_idx_1 >> temp_idx_2 >> temp_rule;
        if (temp_rule == 0) {
            edge_up2down[temp_idx_1].push_back(temp_idx_2);
            indegree_up2down[temp_idx_2]++;
        }
        else if (temp_rule == 1) {
            edge_up2down[temp_idx_2].push_back(temp_idx_1);
            indegree_up2down[temp_idx_1]++;
        } 
        else if (temp_rule == 2) {
            edge_left2right[temp_idx_1].push_back(temp_idx_2);
            indegree_left2right[temp_idx_2]++;
        }
        else if (temp_rule == 3) {
            edge_left2right[temp_idx_2].push_back(temp_idx_1);
            indegree_left2right[temp_idx_1]++;
        }
    }
    for (int i = 0; i < m; i++) {
        if (indegree_up2down[i] == 0) q_up2down.push(i);
        if (indegree_left2right[i] == 0) q_left2right.push(i);
    }
    bool ans_up2down = check(1);
    cout << "ans_up2down" << ans_up2down << endl;
    memset(vis, 0, sizeof(vis));
    bool ans_left2right = check(2);
    cout << "ans_left2right" << ans_left2right << endl;
    bool ans = (ans_up2down & ans_left2right);
    cout << ans;
    return 0;
}