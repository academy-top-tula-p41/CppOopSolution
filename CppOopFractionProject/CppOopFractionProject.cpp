// CppOopFractionProject.cpp 
#include <iostream>
#include "Fraction.h"

int* IntArrayCreate(int size);
Fraction* FractionArrayCreate(int size);

template<typename T>
void ArraySort(T* array, int size);

template<typename T>
void ArrayPrint(T* array, int size);

int main()
{
    Fraction fraction(5, 6);
    std::cout << fraction.ToString() << "\n";

    Fraction other{ fraction };

    other.Numerator(10);
    std::cout << fraction.ToString() << "\n";

    /*std::cout << (fraction++).ToString() << "\n";
    std::cout << fraction.ToString() << "\n";*/

    /*Fraction other = 10 + fraction;
    std::cout << other.ToString() << "\n";*/

    //Fraction result = fraction + other;
    //std::cout << (fraction + other).ToString() << "\n";

    //Fraction f1(2, 5), f2(11, 15), f3(7, 12);

    //std::cout << fraction.Plus(other).Multiply(f1).Minus(f2).ToString();


    /*int* array = IntArrayCreate(10);
    ArrayPrint(array, 10);
    ArraySort(array, 10);
    ArrayPrint(array, 10);*/

    /*Fraction* farray = FractionArrayCreate(10);
    
    ArrayPrint(farray, 10);
    ArraySort(farray, 10);
    ArrayPrint(farray, 10);*/

}

int* IntArrayCreate(int size)
{
    srand(time(nullptr));

    int* array = new int[size];
    for (int i{}; i < size; i++)
        array[i] = rand() % 100;
    return array;
}


Fraction* FractionArrayCreate(int size)
{
    srand(time(nullptr));
    Fraction* array = new Fraction[size];

    for (int i{}; i < size; i++)
    {
        int n = rand() % 51;
        int d = 1 + rand() % 100;
        array[i] = Fraction(n, d);
    }
    return array;
}

template<typename T>
void ArrayPrint(T* array, int size)
{
    for (int i{}; i < size; i++)
        std::cout << array[i] << " ";
    std::cout << "\n";
}

template<typename T>
void ArraySort(T* array, int size)
{
    for (int i{}; i < size; i++)
    {
        for(int j{ size - 1 }; j > i; j--)
            if (array[j] < array[j - 1])
            {
                T temp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = temp;
            }
    }
}
