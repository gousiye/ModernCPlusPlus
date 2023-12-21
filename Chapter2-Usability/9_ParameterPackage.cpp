#include <cstdio>
#include <iostream>


#ifdef __cplusplus
extern "C" {
#endif


    // paramater without template, using stdarg
#include <stdio.h>
#include <stdarg.h>
    int SumNoTemplate(int count, ...) {
        va_list ap;
        va_start(ap, count);
        int sum = 0;
        for (int i = 0; i < count; i++) {
            sum += va_arg(ap, int);
        }
        va_end(ap);
        printf("The result of parameter package of C without template is: %d\n\n", sum);
        return sum;
    }

#ifdef __cplusplus
}
#endif





enum Version {
    Before17, AndBeyond17
};

Version version;

// version before C++17 with template
#if __cplusplus < 201703L

// template parameter package with recursion
template<typename T>
auto SumWithTemplate(T val) -> decltype(val) {
    return val;
}

template<typename T, typename ...Ts>
auto SumWithTemplate(T val, Ts ... args) -> decltype(val) {
    version = Before17;
    return val + SumWithTemplate(args...);
}

// version and beyond C++17 with template
#else
template<typename T, typename ...Ts>
auto SumWithTemplate(T val, Ts ... args) {
    version = AndBeyond17;
    if constexpr (sizeof...(args) > 0) {
        return (val + SumWithTemplate(args...));
    }
    return val;
}

#endif


// parameter package with initializer_list
template<typename T, typename ...Ts>
auto SumWithInitializer(T val, Ts ... args) -> decltype(val) {
    T result = val;
    (void)std::initializer_list<T>{([&args, &result]() {
        result += args;
        }(), val)...};
    return result;
}


int main() {
    SumNoTemplate(3, 1, 2, 3);
    auto var = SumWithTemplate(1, 2, 3);
    if (version == Before17) {
        std::cout << "Before C++ 17:" << std::endl << "    ";
    }
    else {
        std::cout << "AndBeyond C++ 17:" << std::endl << "    ";
    }
    std::cout << "The result of parameter package of C++ with recursion is: " << var << std::endl << std::endl;
    std::cout << "Using initialize_list to unpackage: " << std::endl << "    ";
    auto initialize_var = SumWithInitializer(1.0, 2, 3, 4, 5.5);
    std::cout << initialize_var << std::endl;
    system("pause");
    return 0;
}


