#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node {
public:
    int val = -1;
    Node* lch = nullptr;
    Node* rch = nullptr;
    Node(int __val = 0, Node* __lch = nullptr, Node* __rch = nullptr) :
        val(__val), lch(__lch), rch(__rch) {}
};

Node* EstablishTree(const vector<int>& arr) {
    if (arr.size() == 0) return nullptr;
    queue<pair<Node*, int>> q;
    Node* root = new Node(arr[0]);
    q.push(make_pair(root, 0));
    while (!q.empty()) {
        Node* curr = q.front().first;
        int index = q.front().second;
        q.pop();
        int lindex = 2 * index + 1;
        int rindex = 2 * index + 2;
        if (lindex < arr.size()) {
            Node* lchild = new Node(arr[lindex]);
            curr->lch = lchild;
            q.push(make_pair(lchild, lindex));
            if (rindex < arr.size()) {
                Node* rchild = new Node(arr[rindex]);
                curr->rch = rchild;
                q.push(make_pair(rchild, rindex));
            }
        }
    }
    return root;
}


void Traverse(Node* root) {
    if (root == nullptr) return;
    queue<Node*> q;
    q.push(root);
    q.push(nullptr);
    while (!q.empty()) {
        if (q.size() == 1 && q.front() == nullptr) {
            return;
        }
        Node* curr = q.front();
        q.pop();
        if (curr == nullptr) {
            std::cout << "\n";
            q.push(nullptr);
            continue;
        }
        std::cout << curr->val << " ";
        if (curr->lch) q.push(curr->lch);
        if (curr->rch) q.push(curr->rch);
    }
}

void Delete(Node* root) {
    if (root == nullptr) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        if (curr->lch) q.push(curr->lch);
        if (curr->rch) q.push(curr->rch);
        delete curr;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    vector<int> arr;
    int temp = 0;
    while (std::cin >> temp) {
        arr.push_back(temp);
    }

    Node* root = EstablishTree(arr);
    Traverse(root);
    Delete(root);
    std::cout << std::endl;
    system("pause");
    return 0;
}