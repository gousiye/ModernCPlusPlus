#include <iostream>

template<typename T>
void print(T& t) {
    std::cout << "left" << std::endl;
}

template<typename T>
void print(T&& t) {
    std::cout << "right" << std::endl;
}

template<typename T>
void testForward(T&& v) {
    print(v);
    print(std::forward<decltype(v)>(v));
    print(std::move(v));
}

int main(int argc, char* argv[])
{
    testForward(1);

    std::cout << "======================" << std::endl;

    int x = 1;
    testForward(x);

    system("pause");
    return 0;
}
