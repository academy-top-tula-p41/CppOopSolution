#include <iostream>

class Point
{
protected:
    int x;
    int y;

public:
    Point() : Point(0, 0) {}
    Point(int x, int y) : x{ x }, y{ y } {}

    int& X() { return x; }
    int& Y() { return y; }

    friend std::ostream& operator<<(std::ostream& out, const Point& point)
    {
        out << "(" << point.x << "," << point.y << ")";
        return out;
    }
};

class Line : public Point
{
    int dx, dy;

public:
    Line() : Line(0, 0, 0, 0) {}

    Line(int x, int y, int dx, int dy)
        : Point(x, y), dx{dx}, dy{dy}
    {}
};



class Base
{
protected:
    int protected_value;
public:
    Base()
    {
        protected_value = 0;
        std::cout << "Base construct " << this << "\n";
    }
    Base(int value)
    {
        protected_value = value;
        std::cout << "Base params construct " << this << "\n";
    }

    Base(const Base& other)
    {
        this->protected_value = other.protected_value;
        std::cout << "Base copy construct " << this << "\n";
    }

    ~Base()
    {
        std::cout << "Base destruct " << this << "\n";
    }
};

class Derived : public Base
{
public:
    Derived()
    {
        std::cout << "Derived construct " << this << "\n";
        protected_value = 100;
        //private_value = 200; 
    }

    //using Base::Base;
    Derived(int value) : Base(value)
    {
        std::cout << "Derived params construct " << this << "\n";
        //protected_value = value;
    }

    Derived(const Derived& derived_other) : Base(derived_other)
    {
        std::cout << "Derived copy construct " << this << "\n";
    }

    ~Derived()
    {
        std::cout << "Derived destruct " << this <<  "\n";
    }
};

int main()
{
    //Point point(4, 9);
    //point.X() = 10;
    //std::cout << point << "\n";

    //Line line(10, 20, 30 ,30);
    ////line.X() = 10;
    ////line.Y() = 20;

    //std::cout << line << "\n";

    //Base base;
    /*Derived obj(100);*/
    Derived* obj1 = new Derived(100);
    

    delete obj1;

    /*Derived obj2{ obj1 };*/
}
