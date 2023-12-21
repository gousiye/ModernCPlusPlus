#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct Node {
    int h = 0;  //树的最大深度
    int last = -1; //上一个节点
    vector<int> suffix;
};


int GetRoot(const vector<Node>& nodes, int index) {
    if (nodes[index].last == -1)    //自己就是根节点
        return index;
    while (nodes[index].last != -1) {
        index = nodes[index].last;
    }
    return index;
}


//路径压缩
void Procedure(vector<Node>& nodes, int curr, int rootId) {
    for (int i = 0; i < nodes[curr].suffix.size(); i++) {
        Procedure(nodes, nodes[curr].suffix[i], rootId);
    }
    nodes[curr].suffix.clear();
    nodes[rootId].suffix.push_back(curr);
    nodes[curr].last = rootId;
}

int main() {
    int n = 0;
    int m = 0;
    while (std::cin >> n) {
        if (n == 0) break;
        std::cin >> m;
        vector<Node> nodes(n + 1); //下标从1开始
        int st = 0;
        int ed = 0;
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &st, &ed);
            if (st == ed)    //自己和自己建路忽略
                continue;
            int rootSt = GetRoot(nodes, st);
            int rootEd = GetRoot(nodes, ed);
            if (rootSt == rootEd) {
                continue;
            }
            if (nodes[rootSt].h < nodes[rootEd].h) { //矮树向高树合并
                swap(rootSt, rootEd);
            }
            nodes[rootEd].last = rootSt;
            //树的高度应该最多为2
            Procedure(nodes, rootEd, rootSt);
            nodes[rootSt].h = max(nodes[rootSt].h, nodes[rootEd].h + 1);
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (nodes[i].last == -1)
                ans += 1;
        }
        std::cout << ans - 1 << std::endl;
    }
    system("pause");
    return 0;
}