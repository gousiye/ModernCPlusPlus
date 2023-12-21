#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

// const int INF = 1000000001;
const int MAXV = 100010;
const int MAXE = 200010;

int n, m, source;

struct Edge {
    int ed = -1;
    int w = -1;
    int next = -1;
};

struct Node {
    int x = -1;
    int d = -1;
    bool operator < (const Node& other) const {
        return this->d > other.d;
    }
};

bool vis[MAXV];
int first[MAXV], dist[MAXV];
Edge edges[MAXE];
int cnt = 0;

void Initialize() {
    for (int i = 0; i <= n; i++) {
        vis[i] = false;
        first[i] = -1;
        dist[i] = -1;
    }
    cnt = 0;
}

void AddEdge(int st, int ed, int w) {
    edges[cnt].ed = ed;
    edges[cnt].w = w;
    edges[cnt].next = first[st];
    first[st] = cnt++;
}

void Dijkstra() {
    priority_queue<Node> q;
    q.push({source, 0});
    dist[source] = 0;
    while (!q.empty()) {
        int node = q.top().x;
        int dis = q.top().d;
        q.pop();
        if (vis[node]) continue;
        vis[node] = true;
        dist[node] = dis;
        for (int i = first[node]; i != -1; i = edges[i].next) {
            int ed = edges[i].ed;
            if (!vis[ed] && (dist[ed] == -1 || dist[node] + edges[i].w < dist[ed])) {
                dist[ed] = dist[node] + edges[i].w;
                q.push({ed, dist[ed]});
            }
        }
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &source);
    Initialize();
    for (int i = 0; i < m; i++) {
        int st = 0, ed = 0, w = 0;
        scanf("%d %d %d", &st, &ed, &w);
        AddEdge(st, ed, w);
    }
    Dijkstra();
    for (int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }
    system("pause");
    return 0;
}