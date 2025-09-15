// CppOopFractionProject.cpp 
#include <iostream>
#include "Fraction.h"


int main()
{
    Fraction fraction(25, 30);
    std::cout << fraction.ToString() << "\n";

    Fraction other(4, 7);

    //Fraction result = fraction + other;
    std::cout << (fraction + other).ToString() << "\n";

    Fraction f1(2, 5), f2(11, 15), f3(7, 12);

    //std::cout << fraction.Plus(other).Multiply(f1).Minus(f2).ToString();
    
}


