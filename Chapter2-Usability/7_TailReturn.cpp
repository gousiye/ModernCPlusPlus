#include <cstdio>
#include <iostream>

template<typename T, typename R>
auto add(T x, R y) {
    auto sum = x + y;
    return sum;
}

int main() {
    auto var = add(1, 2.0);
    if (std::is_same<decltype(var), double>::value) {
        std::cout << "double result" << std::endl;
    }
    if (std::is_same<decltype(var), int>::value) {
        std::cout << "int result" << std::endl;
    }
    system("pause");
    return 0;
}