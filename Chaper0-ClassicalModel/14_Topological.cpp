#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

const int MAXV = 110;
const int MAXE = 110;

struct Node {
    int penetration = -1;
    int x = -1;
};

struct Edge {
    int ed = -1;
    int next = -1;
};

int cnt = 0;
int first[MAXV];
Edge edges[MAXE];
Node nodes[MAXV];

void Initialize(int n) {
    for (int i = 0; i < n; i++) {
        first[i] = -1;
        nodes[i].penetration = 0;
        nodes[i].x = i;
    }
    cnt = 0;
}

void AddEdge(int st, int ed) {
    edges[cnt].ed = ed;
    edges[cnt].next = first[st];
    first[st] = cnt++;
    nodes[ed].penetration += 1;
}


bool Topological(int n) {
    bool result = true;
    int count = 0;
    queue<Node> q;
    for (int i = 0; i < n; i++) {
        if (nodes[i].penetration == 0) {
            q.push(nodes[i]);
        }
    }
    while (1) {
        if (q.empty()) {
            return count == n;
        }
        Node tmp = q.front();
        q.pop();
        count += 1;
        for (int i = first[tmp.x]; i != -1; i = edges[i].next) {
            int ed = edges[i].ed;
            nodes[ed].penetration -= 1;
            if (nodes[ed].penetration == 0) {
                q.push(nodes[ed]);
            }
        }
    }
    return false;
}

int main() {
    int n = 0;
    int m = 0;
    Initialize(MAXV);
    while (scanf("%d %d", &n, &m) != EOF) {
        if (n == 0) break;
        for (int i = 0; i < m; i++) {
            int st = 0, ed = 0;
            scanf("%d %d", &st, &ed);
            AddEdge(st, ed);
        }
        bool flag = Topological(n);
        if (flag) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
        Initialize(n);
    }
    system("pause");
    return 0;
}