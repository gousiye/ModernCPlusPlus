#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;


struct Node {
    int a = 0;
    int b = 0;
    Node(int __a = 0, int __b = 0) : a(__a), b(__b) {}
    bool operator < (const Node& other) const {
        return this->a < other.a;
    }
};

struct cmp {
    bool operator ()(const Node& nodeA, const Node& nodeB) {
        return nodeA.a < nodeB.a;
    }
};

void PrinQueue(priority_queue<Node, vector<Node>, cmp>& q) {
    while (!q.empty()) {
        std::cout << q.top().a << " " << q.top().b << std::endl;
        q.pop();
    }
}

void PrinQueue(priority_queue<Node>& q) {
    while (!q.empty()) {
        std::cout << q.top().a << " " << q.top().b << std::endl;
        q.pop();
    }
}


int main() {
    priority_queue<Node, vector<Node>, cmp> q1;
    priority_queue<Node> q2;
    q1.emplace(1, 2);
    q1.emplace(2, 9);
    q1.emplace(-1, -4);
    q2.emplace(1, 2);
    q2.emplace(2, 9);
    q2.emplace(-1, -4);
    PrinQueue(q1);
    PrinQueue(q2);
    system("pause");
    return 0;
}