#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <algorithm>

// VoidPointer is the alias of void (*) (int, int)
typedef void(*VoidPointerType)(int, int);
using VoidPointerUsing = void(*)(int, int);

void Show(int a, int b) {
    std::cout << "a is " << a << ";    b is " << b << std::endl;
}


template<typename T>
class TemplateClass {
public:
    T val;
    void show() {
        std::cout << "The value of the class is " << val << std::endl;
    }
    TemplateClass(T __val) {
        this->val = __val;
    }
    TemplateClass() {}
};


int main() {
    // alias of function with typedef
    VoidPointerType p1 = Show;
    p1(1, 2);
    // alias of function with using
    VoidPointerUsing p2 = Show;
    p2(2, 3);

    // typedef cannot used on template class
    // alias of template class with using
    using IntTemplateClass = TemplateClass<int>;
    IntTemplateClass IntTestClass(12);
    IntTestClass.show();
    std::set<int> t;
    t.insert(1);
    system("pause");
    return 0;
}