#include <cstdio>
#include <iostream>

class Function {
public:
    int operator() () {
        std::cout << "This is a funciton object" << std::endl;
        return 17;
    }

};

int main() {
    Function f;
    int a = f();
    std::cout << a << std::endl;
    system("pause");
    return 0;
}