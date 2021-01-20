#include <bits/stdc++.h>
using namespace std;

struct Edge {
	int u, v, w;
    bool operator < (Edge& a) {
        return this->w < a.w;
    }
} edge[1000007], res[1000007];

int i, m, n, ans;
int is_circle[1000007];

int find(int x) {
	return x == is_circle[x] ? x : is_circle[x] = find(is_circle[x]);
}

int main() {
	cin >> n >> m;
	for (i = 1; i <= m; i++) {
        cin >> edge[i].u >> edge[i].v >> edge[i].w;
        if (edge[i].u > edge[i].v)
            swap(edge[i].u, edge[i].v);
    }
	for (i = 1; i <= n; i++) 
        is_circle[i] = i;
	sort(edge + 1, edge + m + 1);
    int p, q, cnt = 0;
	for (int i = 1; i <= m; i++) {
		p = find(edge[i].u);
		q = find(edge[i].v);
		if (p != q) {
			is_circle[q] = p;
			// ans += edge[i].w;
            res[cnt++] = edge[i];
            if (cnt == m)
                break;
		}
	}
    if (cnt != m - 1) {
        cout << "What the HELL?";
        return 0;
    }
    sort(res, res + cnt, [=](Edge a, Edge b) -> bool {
        if (a.u != b.u) return a.u < b.u;
        else if (a.v != b.v) return a.v < b.v;
        return a.w < b.w;
    });
	for (int i = 0; i < cnt; i++)
        cout << res[i].u << " " << res[i].v << " " << res[i].w << "\n";
	return 0;
}
