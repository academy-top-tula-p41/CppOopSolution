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
public:
    Base() 
    {
        std::cout << "Base construct " << this << "\n";
    }

    ~Base()
    {
        std::cout << "Base destruct " << this << "\n";
    }
};

class Derive : public Base
{
public:
    Derive()
    {
        std::cout << "Derive construct " << this << "\n";
    }

    ~Derive()
    {
        std::cout << "Derive destruct " << this <<  "\n";
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
    Derive derive;
}
