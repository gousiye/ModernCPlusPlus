#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXV = 100;
const int MAXNE = 10000;

struct Node {
    int h = 0;
    int father = -1;
};

struct Edge {
    int st = -1;
    int ed = -1;
    int w = 0;
};

Node nodes[MAXV];
Edge edges[MAXNE];

void Initialize(int n) {
    for (int i = 1; i <= n; i++) {
        nodes[i].father = -1;
        nodes[i].h = 0;
    }
}

bool cmp(const Edge& a, const Edge& b) {
    return a.w < b.w;
}

int Find(int index) {
    if (nodes[index].father == -1)
        return index;
    while (nodes[index].father != -1) {
        index = nodes[index].father;
    }
    return index;
}

bool UnionCollect(int st, int ed) {
    int x = Find(st);
    int y = Find(ed);
    if (x == y) {
        return false;
    }
    if (nodes[x].h >= nodes[y].h) {
        nodes[y].father = x;
        if (nodes[x].h == nodes[y].h) {
            nodes[x].h += 1;
        }
    }
    else {
        nodes[x].father = y;
    }
    return true;
}

int Kruskal(int n, int len) {
    sort(edges, edges + len, cmp);
    int ans = 0;
    for (int i = 0; i < len; i++) {
        if (UnionCollect(edges[i].st, edges[i].ed)) {
            ans += edges[i].w;
        }
    }
    int flag = -1;
    for (int i = 1; i <= n; i++) {
        if (nodes[i].father == -1)
            flag += 1;
    }
    if (flag > 0)return -1;
    return ans;
}

int main() {
    int n = 0;
    while (scanf("%d", &n) != EOF) {
        if (n == 0) break;
        int len = n * (n - 1) / 2;
        for (int i = 0; i < len; i++) {
            scanf("%d %d %d", &edges[i].st, &edges[i].ed, &edges[i].w);
        }
        int ans = Kruskal(n, len);
        printf("%d\n", ans);
        Initialize(len);
    }
    system("pause");
    return 0;
}