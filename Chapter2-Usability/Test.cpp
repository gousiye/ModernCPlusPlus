#include <cstdio>
#include <iostream>

using namespace std;


int main() {

    enum class Test {
        v1,
        v2 = 100
    };
    Test t1 = Test::v1;
    std::cout << t1 << std::endl;

    system("pause");
    return 0;
}