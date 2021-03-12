#include <bits/stdc++.h>
using namespace std;

int M;
int graph[305][305], vis[305][305], dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
int x, y, t;
const int INF = 0x3f3f3f3f;

struct Node {
    int x, y, step;
    Node(int _x, int _y, int _step) : x(_x), y(_y), step(_step) {}
};

int bfs() {
    if (graph[0][0] == INF)
        return 0;
    queue<Node> q;
    q.push(Node(0, 0, 0));
    vis[0][0] = 1;
    while (!q.empty()) {
        Node node = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            Node tmp(node.x + dir[i][0], node.y + dir[i][1], node.step + 1);
            if (tmp.x < 0 || tmp.y < 0)
                continue;
            if (graph[tmp.x][tmp.y] == INF)
                return tmp.step;
            if (tmp.step < graph[tmp.x][tmp.y] && !vis[tmp.x][tmp.y]) {
                q.push(tmp);
                vis[tmp.x][tmp.y] = 1;
            }
        }
    }
    return -1;
}

int main() {
    cin >> M;
    memset(graph, 0x3f, sizeof(graph));
    for (int i = 1; i <= M; i++) {
        cin >> x >> y >> t;
        graph[x][y] = min(graph[x][y], t);
        for (int j = 0; j < 4; j++) {
            int r = x + dir[j][0], c = y + dir[j][1];
            if (r < 0 || c < 0)
                continue;
            graph[r][c] = min(graph[r][c], t);
        }
    }
    cout << bfs();
    return 0;
}