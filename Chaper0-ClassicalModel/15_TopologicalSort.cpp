#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

const int MAXV = 510;
const int MAXE = MAXV * (MAXV - 1) / 2;

struct Edge {
    int ed = -1;
    int next = -1;
};

int cnt = 0;
int first[MAXV];
int penetration[MAXV];
Edge edges[MAXV];

void Initialize(int n) {
    for (int i = 1; i <= n; i++) {
        first[i] = -1;
        penetration[i] = 0;
    }
    cnt = 0;
}

void AddEdge(int st, int ed) {
    edges[cnt].ed = ed;
    edges[cnt].next = first[st];
    first[st] = cnt++;
    penetration[ed] += 1;
}

vector<int> TopologicSort(int n) {
    vector<int> ans;
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 1; i <= n; i++) {
        if (penetration[i] == 0) {
            q.push(i);
        }
    }
    //明确有向无环图了
    while (!q.empty()) {
        int node = q.top();
        q.pop();
        ans.push_back(node);
        for (int i = first[node]; i != -1; i = edges[i].next) {
            int ed = edges[i].ed;
            penetration[ed] -= 1;
            if (penetration[ed] == 0) {
                q.push(ed);
            }
        }
    }
    return ans;
}


int main() {
    int n = 0, m = 0;
    Initialize(MAXV - 1);
    while (scanf("%d %d", &n, &m) != EOF) {
        int st = 0, ed = 0;
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &st, &ed);
            AddEdge(st, ed);
        }
        vector<int> ans = TopologicSort(n);
        for (int i = 0; i < n; i++) {
            if (i == 0) printf("%d", ans[i]);
            else printf(" %d", ans[i]);
        }
        printf("\n");
        Initialize(n);
    }
    system("pause");
    return 0;
}