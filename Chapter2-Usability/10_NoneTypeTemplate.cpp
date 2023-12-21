#include <cstdio>
#include <iostream>

#if __cplusplus >= 201703L


// C++17 entitle user to use auto on none-type parameter
template<auto arrSize>
class Test {
public:
    int arr[arrSize];
};


#else
template<int arrSize>
class Test {
public:
    int arr[arrSize];
};

#endif

int main() {
    std::cout << "Now the version of C++ is: " << __cplusplus << std::endl;
    constexpr int var = 13;
    Test<var>* test = new Test<var>();
    std::cout << sizeof(test->arr) / sizeof(test->arr[0]) << std::endl;
    system("pause");
    return 0;
}