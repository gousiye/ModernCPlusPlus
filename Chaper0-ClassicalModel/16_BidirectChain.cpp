#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXV = 1010;
const int MAXE = 10010;


struct Edge {
    int ed = -1;
    int w;
    int next = -1;
    int last = -1;
};

int cnt;
int from[MAXV], to[MAXV];
Edge edges[2 * MAXE];

void AddEdge(int st, int ed, int w) {
    edges[cnt].ed = ed;
    edges[cnt].w = w;
    edges[cnt].next = from[st];
    from[st] = cnt++;

    edges[cnt].ed = st;
    edges[cnt].w = w;
    edges[cnt].last = to[ed];
    to[ed] = cnt++;
}


int main() {
    int n = 0;
    int m = 0;
    scanf("%d %d", &n, &m);
    memset(from, -1, sizeof(from));
    memset(to, -1, sizeof(to));
    for (int i = 0; i < m; i++) {
        int st = 0, ed = 0, w = 0;
        scanf("%d %d %d", &st, &ed, &w);
        AddEdge(st, ed, w);
    }
    for (int i = to[3]; i != -1; i = edges[i].last) {
        std::cout << edges[i].ed << " " << edges[i].w << std::endl;
    }
    system("pause");
    return 0;
}