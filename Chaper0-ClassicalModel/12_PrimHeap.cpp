#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int MAXE = 10000;
const int MAXV = 100;
const int INF = 2100000000;

struct Edge {
    int next = -1;
    int ed = -1;
    int w = 0;
};

struct Node {
    int x = -1;
    int dis = -1;
    bool operator < (const Node& other) const {
        return this->dis > other.dis;
    }
};

int cnt = 0;
int first[MAXV];
int dist[MAXV];
bool vis[MAXV];
Edge edges[MAXE];

void Initialize(int n, int len) {
    for (int i = 0; i <= len; i++) {
        edges[i].next = -1;
        edges[i].ed = -1;
        edges[i].w = 0;
    }
    for (int i = 0; i <= n; i++) {
        vis[i] = false;
        dist[i] = INF;
        first[i] = -1;
    }
    cnt = 0;
}

void AddEdge(int st, int ed, int w) {
    edges[cnt].ed = ed;
    edges[cnt].w = w;
    edges[cnt].next = first[st];
    first[st] = cnt++;
}

int Prim(int n, int len) {
    int ans = 0;
    int count = 0;
    priority_queue<Node> q;
    q.push({1,0});
    dist[1] = 0;
    while (!q.empty()) {
        int node = q.top().x;
        int dis = q.top().dis;
        q.pop();
        if (vis[node]) { continue; }
        vis[node] = true;
        count += 1;
        ans += dis;
        for (int i = first[node]; i != -1; i = edges[i].next) {
            int ed = edges[i].ed;
            if (!vis[ed] && edges[i].w < dist[ed]) {
                dist[ed] = edges[i].w;
                q.push({ed, edges[i].w});
            }
        }
    }
    if (count < n) {
        return -1;
    }
    return ans;
}

int main() {
    int n = 0;
    memset(first, -1, sizeof(first));
    for (int i = 0; i < MAXV; i++) {
        dist[i] = INF;
    }
    while (scanf("%d", &n) != EOF) {
        if (n == 0) break;
        int len = n * (n - 1) / 2;
        for (int i = 0; i < len; i++) {
            int st = -1;
            int ed = -1;
            int w = 0;
            scanf("%d %d %d", &st, &ed, &w);
            //无向边
            AddEdge(st, ed, w);
            AddEdge(ed, st, w);
        }
        int ans = Prim(n, len);
        std::cout << ans << std::endl;
        Initialize(n, len);
    }
    system("pause");
    return 0;
}