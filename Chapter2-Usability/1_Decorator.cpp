// a simple completion of decorator
#include <cstdio>
#include <iostream>

void greeting() {
    std::cout << "This is a test" << std::endl;
}

// Decorator returns a pointer of function inner
auto Decorator() {
    auto inner = [](int a, int b) {
        std::cout << "This is a decorator and the sum is " << a + b << std::endl;
        greeting();
    };
    auto result = &inner;
    return result;
}

int main() {
#include <iostream>
    using namespace std;
    auto p_test = Decorator();
    (*p_test)(1, 2);
    system("pause");
    return 0;
}