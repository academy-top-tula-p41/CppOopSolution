// CppOopInheritanceSpecificationProject.cpp 
//
#include <iostream>

class Base
{
private:
    int private_value;
protected:
    int protected_value;
public:
    int public_value;
};




//class Derived : public Base
//class Derived : protected Base
//class Derived : private Base
class Derived : Base
{
     
public:
    // using Base::protected_value;
    // using Base::public_value;

    void method()
    {
        this->public_value = 100;
        this->protected_value = 200;
        //this->private_value = 300;
    }
};

int main()
{
    Base base;
    base.public_value;
    // base.protected_value;

    Derived derived;
    derived.public_value;
    derived.protected_value;
}
