#include <cstdio>
#include <iostream>

using namespace std;

class Test {
public:
    int* val = nullptr;
    Test() {
        cout << "Constructor" << endl;
    }
    Test(const Test& other) {
        val = new int(*other.val);
        cout << "Copy Constructor" << endl;
    }
    Test(Test&& other) {
        this->val = other.val;
        other.val = nullptr;
        cout << "Move Constructor" << endl;
    }
    ~Test() {
        delete val;
        cout << "Destructor" << endl;
    }
};


Test getObj() {
    Test obj;
    obj.val = new int(3);
    std::cout << obj.val << std::endl;
    return obj;
}

int main() {
    // Test a;
    // a.val = new int(1);
    // cout << a.val << endl;
    // Test b = move(a);
    // cout << b.val << endl;
    // cout << a.val << endl;

    Test test = getObj();
    std::cout << test.val << std::endl;
    system("pause");
    return 0;
}