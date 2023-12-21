#include <typeinfo>
#include <iostream>
#include <vector>
#include <algorithm>
#include <typeinfo>


int main() {
    std::vector<int> test(12, 0);
    std::vector<int>::iterator i;
    int cnt = 0;
    for (i = test.begin(); i != test.end(); i++) {
        *i = cnt++;
    }
    for (int i : test) {
        std::cout << i << " " << typeid(i).name() << std::endl;
    }
    system("pause");
    return 0;
}