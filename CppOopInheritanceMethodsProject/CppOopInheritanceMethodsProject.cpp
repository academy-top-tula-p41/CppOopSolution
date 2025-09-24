#include <iostream>

class Base
{
protected:
    void ProtectedMethod()
    {
        std::cout << "Base protected method\n";
    }
public:
    void PublicMethod()
    {
        std::cout << "Base public method\n";
    }
};

class Derived : public Base
{
public:
    void PublicMethod()
    {
        Base::PublicMethod();
        std::cout << "Derived public method\n";
    }
};

int main()
{
    Base base;
    base.PublicMethod();

    Derived derived;
    derived.PublicMethod();
}
