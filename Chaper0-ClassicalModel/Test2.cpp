#include <cstdio>
#include <iostream>
#include <vector>

#include <algorithm>

using namespace std;

int main() {
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);
    a.erase(a.begin());

    for (int i = 0; i < a.size(); i++) {
        std::cout << a[i] << " ";
    }
    std::cout << a[2];
    system("pause");
    return 0;
}