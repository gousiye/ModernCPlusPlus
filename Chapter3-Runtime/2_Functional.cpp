#include <cstdio>
#include <iostream>
#include <functional>
#include <initializer_list>

template <typename T>
void show(T val) {
    std::cout << val << std::endl;
}


template <typename T, typename ...Ts>
void show(T val, Ts ...args) {
    std::cout << val << "   ";
    show(args...);
}

template<typename T, typename ...Ts>
struct FunctionWrapper {
    // similar to funcitonal pointer
    std::function<void(T, Ts...)> pointer = nullptr;
    // using function pointer
    //void(*pointer)(T val, Ts ...args) = nullptr;
};


// template is available on `using`
template <typename T>
using testP = T(*)(T a, T b);


int main() {
    FunctionWrapper<int, int, int> instance;
    instance.pointer = show<int, int, int>;
    instance.pointer(1, 2, 3);
    testP<int> p1;
    testP<double> p2;

    //both auto variable and function pointer can be on the lefthand of lambda expression 
    p1 = [](auto a, auto b) -> decltype(a + b) {
        return a + b;
    };
    p2 = [](auto a, auto b) -> decltype(a + b) {
        return a + b;
    };
    std::cout << "lambda function of Sum(Integer): " << p1(1, 2.0) << std::endl;
    std::cout << "lambda function of Sum(Double): " << p2(1.4, 2.0) << std::endl;

    std::cout << "Test whether functional object can handle lambda whose capture list is not empty" << std::endl;
    int a = 1;
    int b = 2;
    std::function<int()> sum = [a, b]() {return a + b; };
    std::cout << "sum is " << sum() << std::endl;


    system("pause");
    return 0;
}