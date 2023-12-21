#include <cstdio>
#include <iostream>
#include <set>
#include <vector>

class Base {
public:
    int a = 2;
    virtual void show() {}
};

class Derived : public Base {
public:
    int b = 3;
};

void Test_Static_Cast(const Derived& son, const Base*& father, const Base* pseudoFather) {
    const Derived* tmp1 = static_cast<const Derived*>(father);
    std::cout << "static_cast:  " << std::endl;
    std::cout << "    base type of derived pointer transforms to derived:  " << tmp1->b << std::endl;

    const Derived* tmp2 = static_cast<const Derived*>(pseudoFather);
    // static_cast dose not check whether the base type can transform to the derived type
    std::cout << "    base type of base pointer transforming to derived type is nullptr? " << (tmp2 == nullptr) << std::endl;

    const Base& tmp3 = static_cast<const Base&>(son);
    std::cout << "    " << "derived type of derived pointer transform to base type: " << tmp3.a << std::endl;
}



void Test_Dynamic_Cast(const Derived& son, const Base*& father, const Base* pseudoFather) {
    const Derived* tmp1 = dynamic_cast<const Derived*>(father);
    std::cout << "dynamic_cast:  " << std::endl;
    std::cout << "    base type of derived pointer transforms to derived:  " << tmp1->b << std::endl;

    // dynamic_cast will check whether the base type can transform to the derived type.
    // if the base type cannot transform to the derived type, then will return nullptr
    const Derived* tmp2 = dynamic_cast<const Derived*>(father);
    tmp2 = dynamic_cast<const Derived*>(pseudoFather);
    std::cout << "    base type of base pointer transforming to derived is nullptr? " << (tmp2 == nullptr) << std::endl;

    const Base& tmp3 = dynamic_cast<const Base&>(son);
    std::cout << "    " << "derived type of derived pointer transform to base type: " << tmp3.a << std::endl;
}

void Test_Const_Cast(const Derived& son, const Base*& father, const Base* pseudoFather) {
    Derived& tmp1 = const_cast<Derived&> (son);
    tmp1.b = 4;
    std::cout << "const cast: " << std::endl;
    std::cout << "    value of b of son is: " << son.b << std::endl;
    std::cout << "    const_cast can use pointer of reference to change the value of const object" << std::endl;
}

int main() {
    const Derived son;
    const Base* father = &son;
    const Base* pseudoFather = new Base();

    //static_cast dose not check whether the base type can transform to the derived type
    Test_Static_Cast(son, father, pseudoFather);

    std::cout << std::endl << std::endl;

    //dynamic_cast can only be used on class with virtual function
    Test_Dynamic_Cast(son, father, pseudoFather);

    std::cout << std::endl << std::endl;

    //const_cast can use pointer of reference to change the value of const object, rather dose nothing basic type
    Test_Const_Cast(son, father, pseudoFather);

    delete(pseudoFather);
    system("pause");
    return 0;
}
