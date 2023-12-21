#include <cstdio>
#include <iostream>
#include <string>

class Test {
public:
    Test() {}
    Test(const Test& other) {
        std::cout << "The copy construction of class Test is called" << std::endl;
    }
};


int main() {
    // the () after the lambda means calling the lambda function.
    int sum = [](int a, int b) -> decltype(a + b) {
        std::cout << "The call of lambda: ";
        return a + b;
    }(1, 2);
    std::cout << sum << std::endl;


#if __cplusplus >= 201402L
    std::cout << std::endl << std::endl;
    std::cout << "C++14 and beyond allows \"auto\" in Lambda parameter" << std::endl;
    auto func = [](auto val1, auto val2) {
        return val1 + val2;
    };
    std::cout << "Lambda on Interger: " << func(1, 2) << std::endl;
    std::cout << "Lambda on String: " << func(static_cast<std::string>("Hello "), static_cast<std::string>("World")) << std::endl;

#endif

    std::cout << std::endl;
    Test a;
    // lambda captures objects by value will cause the copy constructor being called
    auto CopyLambda = [a]() { };

    std::cout << std::endl;

# if __cplusplus >= 201402L
    auto TempSum = [](int a, int b) {return a + b; };
    [sum = TempSum(1, 2)](int times) {std::cout << "Lambda on compound: " << sum * times \
        << std::endl; }(3);
# endif
    system("pause");
    return 0;
}