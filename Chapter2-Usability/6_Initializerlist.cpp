#include <cstdio>
#include <iostream>
#include <algorithm>


class Test {
public:
    int a = 0;
    int b = 0;
    Test(std::initializer_list<int> list) {
        std::cout << "The Initialier list constructor" << std::endl;
        std::initializer_list<int>::iterator iter = list.begin();
        a = *iter;
        iter += 1;
        b = *iter;
    }
};

int main() {
    //  Test test = {1,2};
    Test test{1,2};
    std::cout << test.a << "   " << test.b << std::endl;
    system("pause");
    return 0;
}