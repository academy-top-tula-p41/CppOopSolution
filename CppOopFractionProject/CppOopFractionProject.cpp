// CppOopFractionProject.cpp 
#include <iostream>
#include "Fraction.h"


int main()
{
    Fraction fraction(5, 6);
    std::cout << fraction.ToString() << "\n";

    Fraction other(4, 7);
    //fraction.Add(other);

    std::cout << fraction.ToString() << "\n";

    Fraction f1(2, 5), f2(11, 15), f3(7, 12);

    std::cout << fraction.Plus(other).Multiply(f1).ToString();
    //Minus(f2).
}


