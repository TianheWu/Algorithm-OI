#include <bits/stdc++.h>
using namespace std;

int n, m, is_circle[100005];
struct Edge {
    int u, v, len;
    Edge(int _u, int _v, int _len) : u(_u), v(_v), len(_len) {};
};
vector<Edge> q;
vector<Edge> ans;

int find(int x) {
    return x == is_circle[x] ? x : is_circle[x] = find(is_circle[x]);
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        is_circle[i] = i;
    for (int i = 1; i <= m; i++) {
        int _u, _v, _l;
        cin >> _u >> _v >> _l;
        if (_u > _v)
            q.push_back(Edge(_v, _u, _l));
        else q.push_back(Edge(_u, _v, _l));
    }
    sort(q.begin(), q.end(), [=](Edge a, Edge b) -> bool {return a.len < b.len;});
    for (int i = 0; i < q.size(); i++) {
        Edge& edge = q[i];
        int pu = find(edge.u), pv = find(edge.v);
        if (pu != pv) {
            ans.push_back(edge);
            is_circle[pu] = pv;
            if (ans.size() == n - 1)
                break;
        }
    }
    if (ans.size() != m - 1) {
        cout << "What the HELL?";
        return 0;
    }
    sort(ans.begin(), ans.end(), [=](Edge a, Edge b) -> bool {
        if (a.u != b.u) return a.u < b.u;
        else if (a.v != b.v) return a.v < b.v;
        else if (a.len != b.len) return a.len < b.len;
        else return true;
    });
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i].u << " " << ans[i].v << " " << ans[i].len << "\n";
    return 0;
}