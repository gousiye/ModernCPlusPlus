#include <cstdio>
#include <iostream>
#include <tuple>
#include <map>

int main() {
    std::tuple<int, double, std::string> a = std::make_tuple(1, 2.0, "this is a tuple");
    std::cout << __cplusplus << std::endl;

    // struct bind in C++ 17
#if __cplusplus >= 201703L
    auto [x, ignore, str] = a;
    std::cout << "This is C++17" << std::endl;


    // get value from tuple before C++ 17
#else
    int x = 0;
    std::string str = "";
    std::tie(x, std::ignore, str) = a;
    std::cout << "This is C++ before C++17" << std::endl;
#endif

    // std::set<int> a;
    //a.insert();
    std::cout << "The size of the tuple is: " << std::tuple_size<decltype(a)>::value << std::endl;
    std::cout << x << std::endl;
    std::cout << str << std::endl;

    //Struct bind in C++17 and beyond 
#if __cplusplus >= 201703L

    std::cout << std::endl << std::endl << std::endl << std::endl;
    std::cout << "Now the following is the Struct bind in C++ 17 and beoyond" << std::endl;
    std::cout << std::endl;
    // Struct bind on the struct
    struct TestBind {
        int a = 1;
        int b = 2;
    };
    TestBind testBind;
    auto [vara, varb] = testBind;
    std::cout << "Bind on the struct: " << "a is " << vara << "   b is " << varb << std::endl;
    //Struct bind on the map
    std::map<std::string, std::string> mapTest;

    //map.insert cannot update the value
    mapTest.insert(std::pair<std::string, std::string>("key1", "value1"));
    mapTest.insert(std::pair<std::string, std::string>("key2", "value2"));
    mapTest.insert(std::pair<std::string, std::string>("key3", "value3"));
    mapTest.insert(std::pair<std::string, std::string>("key3", "value3"));
    mapTest.insert(std::pair<std::string, std::string>("key1", "__value1"));
    std::cout << std::endl;
    std::cout << "Bind on the map" << std::endl;
    for (const auto& [key, value] : mapTest) {
        std::cout << key << "   " << value << std::endl;
    }
#endif

    system("pause");
    return 0;
}